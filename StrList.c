#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"



//יצירת הרשימה
Node *input_list(List *list) {
  char string[1024]; // הגדרת מערך תווים בגודל קבוע
  
  printf("%s", "insret node(./ to END): ");
  scanf("%s", string);

  // קבלת מחרוזות מהמשתמש עד להזנת מחרוזת ריקה
  while (strcmp(string, "./") != 0){
    // הסרת תו השורה החדשה מהסוף
    string[strcspn(string, " ")] = '\0';
    

    // יצירת צומת חדש
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
      // שגיאה בהקצאת זיכרון
      return NULL;
    }

    // העתקת המחרוזת לצומת חדש
    new_node->string = strdup(string);

    // printf("%s",new_node->string);
    // printf("%s","\n");
    if (new_node->string == NULL) {
      // שגיאה בהעתקת מחרוזת
      free(new_node);
      // free(string);
      return NULL;
    }

    // הוספת הצומת החדש לרשימה
    add_string(&list->head, new_node->string);

    scanf("%s", string);
    
  }

  return list->head;
}




//יצירת הרשימה על פי דרישת מספר המילים
Node *input_list_by_num(List *list,int number) {

  char string[1024]; // הגדרת מערך תווים בגודל קבוע

  for (int i = 0; i < number; i++)
  {
    scanf("%s", string);
    string[strcspn(string, " ")] = '\0';
    

    // יצירת צומת חדש
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
      // שגיאה בהקצאת זיכרון
      return NULL;
    }

    // העתקת המחרוזת לצומת חדש
    new_node->string = strdup(string);

    // printf("%s",new_node->string);
    // printf("%s","\n");
    if (new_node->string == NULL) {
      // שגיאה בהעתקת מחרוזת
      free(new_node);
      // free(string);
      return NULL;
    }

    // הוספת הצומת החדש לרשימה
    add_string(&list->head, new_node->string);
  }
 
  return list->head;

}


// פונקציה להוספת מחרוזת לרשימה
void add_string(Node **head, char *string) {
  Node *new_node = malloc(sizeof(Node));
  new_node->string = string;
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
    return;
  }

  Node *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_node;
}



// הדפסת כל מחרוזות הרשימה
void print_strings(Node *head) {
  if (head == NULL)
  {
    printf("%s", "(null))\n");
  }
  
  while (head != NULL) {
    printf("%s", head->string);
    if (head->next != NULL)
    {
      printf(" ");
    }
    head = head->next;
  }
  printf("\n");
}



//מחיקת כל הרשימה
void delete_list(List *list) {
  while (list->head != NULL) {
  Node *next = list->head->next;
  free(list->head);
  list->head = next;
}
  // printf("%s", "List is empty\n");
  list->tail = NULL;
}



//הכנסת צומת באינקס מסויים
void addIn_string(List *list, int j, char *string) {
  Node *new_node = malloc(sizeof(Node));
  if (new_node == NULL) {
    // שגיאה בהקצאת זיכרון
    printf("malloc error\n");
    return;
  }

  new_node->string = strdup(string);
  if (new_node->string == NULL) {
    // בעיה בהכנסת המחרוזת
    printf("string strdup error\n");
    free(new_node);
    return;
  }

  if (list->head == NULL)
  {
    list->head = new_node;
    return;
  }

  Node *current = list->head;

  for (int i = 1; i < j && current != NULL; i++) {
    //ריצה עד לצומת הרצוייה
    current = current->next;
  }

  if (current == NULL) {
    //הגענו לסוף הרשימה נוסיף צומת חדשה ונסיים
    add_string(&list->head, new_node->string);
    return;
  }

  // שמירה על מיקום הצומת הבא
  Node *temp_node = current->next;

  // הכנסת הצומת החדש לאחר הצומת הנוכחי
  current->next = new_node;
  new_node->next = temp_node;

}



//הדפסת אורך הרשימה
int list_length(Node *head) {
  int length = 0;
  if (head == NULL)
  {
    //רשימה ריקה
    // printf("%s", "List length is 0\n");
    return 0;
  }
  
  while (head != NULL) {
    //ריצה עד סוף הרשימה תוך כדי ספירה
    head = head->next;
    length = length +1;
  }
  //הדפסת הספירה (אורך הרשימה)
  return length;

}



//הדפסת מחרוזת באינדקס מסויים
void printIn(Node *head,int j) {
  if (head == NULL)
  {
    printf("%s", "(null))\n");
  }
  for (int i = 0; i < j; i++)
  {
    head = head->next;
  }
  printf("%s", head->string);
  printf("\n");
}



//הדפסת מספר תווים ברשימה
int count_chars(Node *head) {
  int total_chars = 0;

  if (head == NULL)
  {
    return 0;
  }
  
  while (head != NULL) {
    int chars_in_node = strlen(head->string);
    total_chars += chars_in_node;
    head = head->next;
  }
  return total_chars;
}



//ספירת הופעת מחרוזת
int count_repeat(Node *head,char *str) {
  int total_repeat = 0;

  if (head == NULL)
  {
    return 0;
  }
  
  while (head != NULL) {
    if (strcmp(head->string, str) == 0)
    {
      total_repeat = total_repeat + 1;
    }
    head = head->next;
  }
  return total_repeat;
}



//מחיקת צומת עפ"י מחרוזת נתונה
Node *delete_node(List *list, const char *str) {
  Node *prev = NULL;
  Node *current = list->head;
  Node *to_delete;

  // מציאת כל הצמתים המכילים את המחרוזת
  while (current != NULL) {
    if (strcmp(current->string, str) == 0) {
      // שמירת הצומת למחיקה
      to_delete = current;

      //מחיקת הצומת
      if (prev == NULL) {
        list->head = current->next;
      } else {
        prev->next = current->next;
      }

      current = current->next;

      
      free(to_delete);
    } else {
      // מעבר לצומת הבא
      prev = current;
      current = current->next;
    }
  }

  return current;
}



//מחיקת צומת עפ"י אינדקס
Node *delete_node_i(List *list, int j) {
  Node *prev = NULL;
  Node *current = list->head;

  // מציאת הצומת המכיל את המחרוזת
  for (int i = 0; i < j && current != NULL; i++)
  {
    prev = current;
    current = current->next;
  }

  // מחיקת הצומת
  if (current != NULL) {
    if (prev == NULL) {
      // מחיקת הצומת הראשון
      list->head = current->next;
    } else {
      prev->next = current->next;
    }

    free(current);
  }

  return current;
}



//היפוך הרשימה
void reverse_list(List *list) {
  Node *prev = NULL;
  Node *current = list->head;
  Node *next;

  // היפוך המצביעים של כל צומת
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  list->head = prev;
}



//סידור הרשימה לפי סדר קסיקוגרפי
void sort_list(List *list) {
  //bubble sort

  Node *current = list->head;
  Node *next;

  while (current != NULL) {
    next = current->next;

    while (next != NULL) {
      if (strcmp(current->string, next->string) > 0) {
        // החלפת נתונים בין שני צמתים
        swap_nodes(current, next);
      }

      next = next->next;
    }

    current = current->next;
  }
}

//פונקציית עזר להחלפת צמתים
void swap_nodes(Node *a, Node *b) {
  char *temp = a->string;
  a->string = b->string;
  b->string = temp;
}



//בדיקה האם הרשימה מסודרת לפי סדר לקסיקוגרפי
int lexicographic_chack(List *list) {
  Node *current = list->head;
  Node *next;

  while (current != NULL) {
    next = current->next;

    if (next != NULL && strcmp(current->string, next->string) > 0) {
      return 0;
    }

    current = current->next;
  }

  return 1;
}
