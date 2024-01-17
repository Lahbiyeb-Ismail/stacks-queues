#include "monty.h"

void free_memory(void)
{
	free_stack(&globals_var.head);
	fclose(globals_var.file);
}
