#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ShoppingItem {
    char name[50]; // 商品名称
    int quantity; // 商品数量
    struct ShoppingItem* next; // 指向下一个节点的指针
};

// 然后，我们创建一个链表头指针，表示购物清单的起始点：
struct ShoppingItem* shoppingList = NULL; // 初始化购物清单为空

// 1. 添加商品到购物清单：
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

// 2. 从购物清单中移除商品：
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

// 3. 查看购物清单：
void displayList() {
    struct ShoppingItem* current = shoppingList;
    printf("购物清单:\n");
    while (current != NULL) {
        printf("%s - 数量：%d\n", current->name, current->quantity);
        current = current->next;
    }
}

// 4. 修改购物清单中商品的数量：
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

// 5. 清空购物清单：
void clearList() {
    while (shoppingList != NULL) {
        struct ShoppingItem* temp = shoppingList;
        shoppingList = shoppingList->next;
        free(temp);
    }
}

// 6. 计算购物清单中商品的总数量：
int totalQuantity() {
    struct ShoppingItem* current = shoppingList;
    int total = 0;
    while (current != NULL) {
        total += current->quantity;
        current = current->next;
    }
    return total;
}

// 7. 查找购物清单中的商品：
void findItem(char itemName[]) {
    struct ShoppingItem* current = shoppingList;
    printf("查找商品 \"%s\" ：\n", itemName);
    int found = 0;
    while (current != NULL) {
        if (strcmp(current->name, itemName) == 0) {
            printf("%s - 数量：%d\n", current->name, current->quantity);
            found = 1;
        }
        current = current->next;
    }
    if (!found) {
        printf("未找到商品 \"%s\"。\n", itemName);
    }
}

// 8. 排序购物清单：
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

// 9. 合并购物清单：
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
    *list2 = NULL; // 清空第二个购物清单的头指针，防止误用
}

// 10. 删除购物清单中的商品：
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
		printf("\n购物清单\n");
		printf("1.添加商品\n");
		printf("2.移除商品\n");
		printf("3.查看购物清单\n");
		printf("4.修改商品数量\n");
		printf("5.清空清单\n");
		printf("6.计算商品总数量\n");
		printf("7.查找清单中的商品\n");
		printf("8.排序购物清单\n");
		printf("9.合并购物清单\n");
		printf("10.删除商品\n");
		printf("0.退出\n");
			scanf("%d",&node);
			while(node!=0&&node<10)
			{
				if(node==1)
				{
				 printf("请输入要添加的商品名称：");
                scanf("%s", name);
                printf("请输入商品数量：");
                scanf("%d", &shuliang);
                addItem(name, shuliang);
                printf("已成功添加到购物清单。\n");
                break;
				}
				else if(node==2)
				{
				 printf("请输入要移除的商品名称：");
                scanf("%s", name);
                removeItem(name);
                printf("已成功移除商品。\n");
                break;
				 } 
				 else if(node==3)
				 {
				 	 displayList();
                	break;
				 }
				 else if(node==4)
				 {
				  printf("请输入要修改数量的商品名称：");
                scanf("%s", name);
                printf("请输入新的商品数量：");
                scanf("%d", &shuliang);
                updateQuantity(name, shuliang);
                printf("已成功修改商品数量。\n");
                break;
				 }
				 else if(node==5)
				 {
				clearList();
                printf("购物清单已清空。\n");
                break; 	
				 }
				 else if(node==6)
				 {
				 printf("购物清单中商品的总数量为：%d\n", totalQuantity());
                break;
				 }
				 else if(node==7)
				 {
				 printf("请输入要查找的商品名称：");
                scanf("%s", name);
                findItem(name);
                break;
				 }
				 else if(node==8)
				 {
				 sortList();
                printf("购物清单已排序。\n");
                break;	
				 }
				 else if(node==9)
				 {
				 	struct ShoppingItem* list2 = NULL;
				  printf("请先创建第二个购物清单：\n");
                mergeLists(&shoppingList, &list2);
                printf("购物清单已合并。\n");
                break;
				 }
				 else if(node==10)
				 {
				printf("请输入要删除的商品名称：");
                scanf("%s", name);
                printf("是否删除所有匹配商品？（1-是，0-否）：");
                scanf("%d", &shuliang);
                deleteItem(name, shuliang);
                printf("已成功删除商品。\n");
                break;
				 }
			}
			if(node==0)
			break;
			if(node>10&&node<0)
			{
			printf("无效的选择，请重新输入。\n");
                break;
			}
	}
	return 0;
}

