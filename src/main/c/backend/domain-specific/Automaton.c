#include "Automaton.h"

/* MODULE INTERNAL STATE */

static Logger * _logger = NULL;

/** Shutdown module's internal state. */
void _shutdownAutomatonModule() {
	if (_logger != NULL) {
		logDebugging(_logger, "Destroying module: Automaton...");
		destroyLogger(_logger);
		_logger = NULL;
	}
}

ModuleDestructor initializeAutomatonModule() {
	_logger = createLogger("Automaton");
	return _shutdownAutomatonModule;
}

/** PRIVATE FUNCTIONS */

/** PUBLIC FUNCTIONS */


ComputationResult computeAutomaton(Automaton * automaton) {
	ComputationResult computationResult = {
		.succeeded = true,
		.type = automaton->type
	};
	return computationResult;
}
