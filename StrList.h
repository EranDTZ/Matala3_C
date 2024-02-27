
// הגדרת מבנה נתונים עבור צומת ברשימה
typedef struct node {
  char *string;
  struct node *next;
} Node;

// הגדרת מבנה נתונים עבור רשימה
typedef struct list {
  Node *head;
  Node *tail;
} List;

// פונקציות לניהול רשימה

// יצירת רשימה ריקה
List *create_list();

// קבלת מחרוזות מהמשתמש והוספתן לרשימה
Node *input_list(List *list);

//יצירת הרשימה על פי דרישת מספר המילים
Node *input_list_by_num(List *list,int number);

// הוספת מחרוזת לרשימה
void add_string(Node **head, char *string);

// הדפסת כל מחרוזות ברשימה
void print_strings(Node *head);

// שחרור זיכרון שהוקצה לרשימה
void delete_list(List *list);

//הכנסת צומת באינקס מסויים
void addIn_string(List *list,int j,char *string);

//הדפסת אורך הרשימה
int list_length(Node *head);

//הדפסת מחרוזת באינדקס מסויים
void printIn(Node *head,int j);

//הדפסת מספר תווים ברשימה
int count_chars(Node *head);

//ספירת הופעת מחרוזת
int count_repeat(Node *head,char *str);

//מחיקת צומת עפ"י מחרוזת נתונה
Node *delete_node(List *list, const char *str);

//מחיקת צומת עפ"י אינדקס
Node *delete_node_i(List *list, int j);

//היפוך הרשימה
void reverse_list(List *list);

//סידור הרשימה לפי סדר קסיקוגרפי
void sort_list(List *list);

//פונקציית עזר להחלפת צמתים
void swap_nodes(Node *a, Node *b);

//בדיקה האם הרשימה מסודרת לפי סדר לקסיקוגרפי
int lexicographic_chack(List *list);
