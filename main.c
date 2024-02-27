#include <stdio.h>
#include "StrList.c"



int main(){

    List list;
    list.head = NULL;
    list.tail = NULL;
    int i;

    while (1){
        
        scanf("%d",&i);

        if (i==1)
        {
            int index = 0;
            // printf("insert number of words: \n");
            scanf("%d",&index);
            if (index < 0) {
                printf("index error\n");
                return 0;
            }
            // קבלת רשימת מחרוזות מהמשתמש
            input_list_by_num(&list,index);
            // printf("Done \n");

        }
        if (i==2)
        {   
            int index = 0;
            // printf("insert index: \n");
            int input;
            scanf("%d", &input);
            int list_size = list_length(list.head);
            if (input < 0 || input >= 1024 || input > list_size) {
                printf("index error\n");
                return 0;
            }
            index = input;

            char string[1024];

            // printf("insert srting: \n");
            scanf("%s", string);

            addIn_string(&list,index,string);

            // printf("Done \n");
        }
        if (i==3)
        {
            print_strings(list.head);
        }
        if (i==4)
        {
            // printf("List length is %d\n", list_length(list.head));
            printf("%d\n", list_length(list.head));
        }
        if (i==5)
        {
            int index = 0;
            // printf("insert index: \n");
            scanf("%d",&index);
            if (index < 0 || index > list_length(list.head)) {
                printf("index error\n");
                return 0;
            }
            printIn(list.head,index);
        }
        if (i==6)
        {
            // printf("number of chars in the list is %d\n", count_chars(list.head));
            printf("%d\n", count_chars(list.head));
        }
        if (i==7)
        {
            char string[1024];
            // printf("insert srting: \n");
            scanf("%s", string);
            // printf("The word appears %d times\n",count_repeat(list.head,string));
            printf("%d\n",count_repeat(list.head,string));
        }
        if (i==8)
        {
            char string[1024];
            // printf("insert srting: \n");
            scanf("%s", string);
            delete_node(&list,string);
            // printf("Done \n");
        }
        if (i==9)
        {
            int index = 0;
            // printf("insert index: \n");
            scanf("%d",&index);
            if (index < 0 || index > list_length(list.head)) {
                printf("index error\n");
                return 0;
            }
            delete_node_i(&list,index);
            // printf("Done \n");
        }
        if (i==10)
        {
            reverse_list(&list);
            // printf("Done \n");
        }
        if (i==11)
        {
            delete_list(&list);
        }
        if (i==12)
        {
            sort_list(&list);
            // printf("sorted the list by lexicographic order\n");
        }
        if (i==13)
        {
            if (lexicographic_chack(&list))
            {
                // printf("YES the list is sorted by lexicographic order\n");
                printf("true\n");
            }
            else
            {
                // printf("NO the list is NOT sorted by lexicographic order\n");
                printf("false\n");
            }
            
        }
        if (i==0)
        {   
            printf("\n");
            return 0;
        }
        
    }
}
