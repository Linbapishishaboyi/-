#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ShoppingItem {
    char name[50]; // ��Ʒ����
    int quantity; // ��Ʒ����
    struct ShoppingItem* next; // ָ����һ���ڵ��ָ��
};

// Ȼ�����Ǵ���һ������ͷָ�룬��ʾ�����嵥����ʼ�㣺
struct ShoppingItem* shoppingList = NULL; // ��ʼ�������嵥Ϊ��

// 1. �����Ʒ�������嵥��
void addItem(char itemName[], int itemQuantity) {
    struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
    strcpy(newItem->name, itemName);
    newItem->quantity = itemQuantity;
    newItem->next = NULL;

    if (shoppingList == NULL) {
        shoppingList = newItem;
    } else {
        struct ShoppingItem* current = shoppingList;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newItem;
    }
}

// 2. �ӹ����嵥���Ƴ���Ʒ��
void removeItem(char itemName[]) {
    struct ShoppingItem* current = shoppingList;
    struct ShoppingItem* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, itemName) == 0) {
            if (previous != NULL) {
                previous->next = current->next;
            } else {
                shoppingList = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

// 3. �鿴�����嵥��
void displayList() {
    struct ShoppingItem* current = shoppingList;
    printf("�����嵥:\n");
    while (current != NULL) {
        printf("%s - ������%d\n", current->name, current->quantity);
        current = current->next;
    }
}

// 4. �޸Ĺ����嵥����Ʒ��������
void updateQuantity(char itemName[], int newItemQuantity) {
    struct ShoppingItem* current = shoppingList;
    while (current != NULL) {
        if (strcmp(current->name, itemName) == 0) {
            current->quantity = newItemQuantity;
            break;
        }
        current = current->next;
    }
}

// 5. ��չ����嵥��
void clearList() {
    while (shoppingList != NULL) {
        struct ShoppingItem* temp = shoppingList;
        shoppingList = shoppingList->next;
        free(temp);
    }
}

// 6. ���㹺���嵥����Ʒ����������
int totalQuantity() {
    struct ShoppingItem* current = shoppingList;
    int total = 0;
    while (current != NULL) {
        total += current->quantity;
        current = current->next;
    }
    return total;
}

// 7. ���ҹ����嵥�е���Ʒ��
void findItem(char itemName[]) {
    struct ShoppingItem* current = shoppingList;
    printf("������Ʒ \"%s\" ��\n", itemName);
    int found = 0;
    while (current != NULL) {
        if (strcmp(current->name, itemName) == 0) {
            printf("%s - ������%d\n", current->name, current->quantity);
            found = 1;
        }
        current = current->next;
    }
    if (!found) {
        printf("δ�ҵ���Ʒ \"%s\"��\n", itemName);
    }
}

// 8. �������嵥��
void sortList() {
    struct ShoppingItem* current = shoppingList;
    struct ShoppingItem* nextItem = NULL;
    char tempName[50];
    int tempQuantity;

    while (current != NULL) {
        nextItem = current->next;
        while (nextItem != NULL) {
            if (strcmp(current->name, nextItem->name) > 0) {
                strcpy(tempName, current->name);
                strcpy(current->name, nextItem->name);
                strcpy(nextItem->name, tempName);
                tempQuantity = current->quantity;
                current->quantity = nextItem->quantity;
                nextItem->quantity = tempQuantity;
            }
            nextItem = nextItem->next;
        }
        current = current->next;
    }
}

// 9. �ϲ������嵥��
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
    if (*list1 == NULL) {
        *list1 = *list2;
    } else {
        struct ShoppingItem* current = *list1;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = *list2;
    }
    *list2 = NULL; // ��յڶ��������嵥��ͷָ�룬��ֹ����
}

// 10. ɾ�������嵥�е���Ʒ��
void deleteItem(char itemName[], int deleteAll) {
    struct ShoppingItem* current = shoppingList;
    struct ShoppingItem* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, itemName) == 0) {
            if (prev == NULL) {
                struct ShoppingItem* temp = shoppingList;
                shoppingList = shoppingList->next;
                free(temp);
                if (!deleteAll) break;
            } else {
                prev->next = current->next;
                free(current);
                current = prev->next;
                if (!deleteAll) break;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}
int main()
{
	int node;
	char name[20];
	int shuliang;
	while(1)
	{
		printf("\n�����嵥\n");
		printf("1.�����Ʒ\n");
		printf("2.�Ƴ���Ʒ\n");
		printf("3.�鿴�����嵥\n");
		printf("4.�޸���Ʒ����\n");
		printf("5.����嵥\n");
		printf("6.������Ʒ������\n");
		printf("7.�����嵥�е���Ʒ\n");
		printf("8.�������嵥\n");
		printf("9.�ϲ������嵥\n");
		printf("10.ɾ����Ʒ\n");
		printf("0.�˳�\n");
			scanf("%d",&node);
			while(node!=0&&node<10)
			{
				if(node==1)
				{
				 printf("������Ҫ��ӵ���Ʒ���ƣ�");
                scanf("%s", name);
                printf("��������Ʒ������");
                scanf("%d", &shuliang);
                addItem(name, shuliang);
                printf("�ѳɹ���ӵ������嵥��\n");
                break;
				}
				else if(node==2)
				{
				 printf("������Ҫ�Ƴ�����Ʒ���ƣ�");
                scanf("%s", name);
                removeItem(name);
                printf("�ѳɹ��Ƴ���Ʒ��\n");
                break;
				 } 
				 else if(node==3)
				 {
				 	 displayList();
                	break;
				 }
				 else if(node==4)
				 {
				  printf("������Ҫ�޸���������Ʒ���ƣ�");
                scanf("%s", name);
                printf("�������µ���Ʒ������");
                scanf("%d", &shuliang);
                updateQuantity(name, shuliang);
                printf("�ѳɹ��޸���Ʒ������\n");
                break;
				 }
				 else if(node==5)
				 {
				clearList();
                printf("�����嵥����ա�\n");
                break; 	
				 }
				 else if(node==6)
				 {
				 printf("�����嵥����Ʒ��������Ϊ��%d\n", totalQuantity());
                break;
				 }
				 else if(node==7)
				 {
				 printf("������Ҫ���ҵ���Ʒ���ƣ�");
                scanf("%s", name);
                findItem(name);
                break;
				 }
				 else if(node==8)
				 {
				 sortList();
                printf("�����嵥������\n");
                break;	
				 }
				 else if(node==9)
				 {
				 	struct ShoppingItem* list2 = NULL;
				  printf("���ȴ����ڶ��������嵥��\n");
                mergeLists(&shoppingList, &list2);
                printf("�����嵥�Ѻϲ���\n");
                break;
				 }
				 else if(node==10)
				 {
				printf("������Ҫɾ������Ʒ���ƣ�");
                scanf("%s", name);
                printf("�Ƿ�ɾ������ƥ����Ʒ����1-�ǣ�0-�񣩣�");
                scanf("%d", &shuliang);
                deleteItem(name, shuliang);
                printf("�ѳɹ�ɾ����Ʒ��\n");
                break;
				 }
			}
			if(node==0)
			break;
			if(node>10&&node<0)
			{
			printf("��Ч��ѡ�����������롣\n");
                break;
			}
	}
	return 0;
}

