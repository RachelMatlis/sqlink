//#include <stdio.h>
#include"stack.h"
#include <stdio.h> 

#define EXIT -1

static void pushToStack(Stack** Stack);
static void showMenue();

int main()
{
	Stack* stack = NULL;
	int option, data, ret;;

	createStack(&stack);
	if (!stack) {
		return 0;
	}

	showMenue();
	option = 1;
	while (option != EXIT)
	{
		printf("Choose option:\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			pushToStack(&stack);
			break;
		case 2:
			ret= pop(&stack);
			printf("pop: %d\n", ret);
			break;
		case 3:
			ret = top(stack);
			printf("top: %d\n", ret);
			break;
		case 4:
			ret = isEmpty(stack);
			ret == 1 ? printf("YES\n") : printf("NO\n");
			break;
		case 5:
			printStack(stack);
			break;
		case EXIT:
			printf("--> Goodbye\n");
			break;
		default:
			break;
		}
	}

	freeStack(&stack);
	return 0;
}

static void pushToStack(Stack** Stack)
{
	int data = 0;
	printf("Enter data (press -1 to stop):\n");
	scanf("%d", &data);
	while (data != -1)
	{
		push(Stack, data);
		scanf("%d", &data);
	}
}

static void showMenue()
{
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Top\n");
	printf("4. Is empty ?\n");
	printf("5. Print Stack\n");
	printf("Press -1 to exit \n");
}
