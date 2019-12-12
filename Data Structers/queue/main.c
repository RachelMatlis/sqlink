//#include <stdio.h>
#include"queue.h"
#include <stdio.h> 

#define EXIT -1

static void pushToQueue(Queue** queue);
static void showMenue();

int main()
{
	Queue* queue = NULL;
	int option, data, ret;;

	createQueue(&queue);
	if (!queue) {
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
			pushToQueue(&queue);
			break;
		case 2:
			ret = dequeue(&queue);
			printf("--> dequeue: %d\n", ret);
			break;
		case 3:
			ret = peek(queue);
			printf("--> peek: %d\n", ret);
			break;
		case 4:
			ret = isempty(queue);
			ret == 1 ? printf("--> YES\n") : printf("--> NO\n");
			break;
		case 5:
			printf("--> Queue elements:\n");
			printQueue(queue);
			break;
		case EXIT:
			printf("--> Goodbye\n");
			break;
		default:
			break;
		}
	}

	freeQueue(&queue);
	return 0;
}

static void pushToQueue(Queue** queue)
{
	int data = 0;
	printf("Enter data (press -1 to stop):\n");
	scanf("%d", &data);
	while (data != -1)
	{
		enqueue(queue, data);
		scanf("%d", &data);
	}
}

static void showMenue()
{
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Peek\n");
	printf("4. Is empty ?\n");
	printf("5. Print queue\n");
	printf("Press -1 to exit \n");
}
