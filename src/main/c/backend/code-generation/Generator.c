#include "Generator.h"

/* MODULE INTERNAL STATE */

const char _indentationCharacter = ' ';
const char _indentationSize = 4;
static Logger * _logger = NULL;

static FILE *output_file;

/** Shutdown module's internal state. */
void _shutdownGeneratorModule() {
	if (_logger != NULL) {
		logDebugging(_logger, "Destroying module: Generator...");
		destroyLogger(_logger);
		_logger = NULL;
	}
}

ModuleDestructor initializeGeneratorModule() {
	_logger = createLogger("Generator");
	return _shutdownGeneratorModule;
}

/** PRIVATE FUNCTIONS */

static void _generateStatement(Statement* statement);
static void _generatePrologue(void);
static void _generateAutomaton(Automaton* automaton);
static char *  _AutomatonTypeToString(AutomatonType type);
static void _PrintStringList(StringList* list);
static void _output(const char * const format, ...);

static void _generateStatement(Statement* statement) {
	switch (statement->type) {
		case AUTOMATON_STATEMENT:
			_generateAutomaton(statement->automaton);
			break;

		case TEST_STATEMENT:
			break;

		case CONVERSION_STATEMENT:
			break;

		case SHOW_STATEMENT:
			break;

		case PRINT_STATEMENT:
			break;

		case EQUIVALENT_STATEMENT:
			break;

		case UPDATE_STATEMENT:
			break;

		case STRING_DECLARATION_STATEMENT:
			break;

		case FOR_STATEMENT:
			break;

		default:
			logError(_logger, "The specified statement type is unknown: %d", statement->type);
			break;
	};
}

/**
 * Creates the prologue of the generated output, a MarkDown document that 
 * renders the operations being made
 */
static void _generatePrologue(void) {
	_output("%s\n\n", "# Automaton program");
}


static void _generateAutomaton(Automaton* automaton) {
	_output("%s\n\n", "## Automaton definition");

	// List properties
	_output("- **ID**: %s\n", 
		automaton->id
		);
	_output("- **Type**: %s\n", 
		_AutomatonTypeToString(automaton->type)
		);
	_output("- **Alphabet**: "); 
	_PrintStringList(automaton->definition->alphabet);

	_output("- **States**: "); 
	_PrintStringList(automaton->definition->states);

	_output("- **Start state**: %s\n", automaton->definition->startState); 

	_output("- **Accept states**: "); 
	_PrintStringList(automaton->definition->acceptStates);
}

static char * _AutomatonTypeToString(AutomatonType type) {
	switch (type) {
		case DFA:
			return "DFA";
		case NFA:
			return "NFA";
		case LNFA:
			return "LNFA";
	};

	return "UNKNOWN";
}

/**
 * Generates the output of the program.
 */
static void _generateProgram(Program * program) {
	// TODO: Pass all the statements
	_generateStatement(&program->statements[0]);
}

/**
 * Outputs a formatted string to standard output. The "fflush" instruction
 * allows to see the output even close to a failure, because it drops the
 * buffering.
 */
static void _output(const char * const format, ...) {
	va_list arguments;
	va_start(arguments, format);
	vfprintf(output_file, format, arguments);
	fflush(output_file);
	va_end(arguments);
}


static void _PrintStringList(StringList* list) {
	
	if (list->next == NULL) {
		_output("%s\n", list->value);
		return ;
	}

	_output("%s, ", list->value);
	
	_PrintStringList(list->next);
}

/** PUBLIC FUNCTIONS */

void executeGenerator(CompilerState * compilerState) {
	logDebugging(_logger, "Generating final output...");

	// Open output file
	output_file = fopen("output.md", "w");

	_generatePrologue();
	_generateProgram(compilerState->abstractSyntaxtTree);

	fclose(output_file);

	logDebugging(_logger, "Generation is done.");
}
