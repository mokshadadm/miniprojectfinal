typedef struct book {
	int id;
	char name[50];
	char author[50];
	int quantity;
	float price;
	char cat[50];
}book;
book b1, b2;

typedef struct member {
	int id;
	char name[50];
	long contact;
	char emailid[50];
	char joindate[10];
	int availablecards;
}member;
member m1, m2;

int window_1(WINDOW *win,int);
int window_2(WINDOW *win, int);
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);
char *string(char *ch);
int mainmenu(WINDOW *my_win);
int addbook(WINDOW *win);
int addmem(WINDOW *win);
int mem(WINDOW *win);
int add_to_file(FORM *form, FIELD **field);
int addmem_to_file(FORM *form, FIELD **field);
int issuesection(WINDOW *win);
int issue(WINDOW *win);
int issuerecord_to_file(FORM *form, FIELD **field);
int returnbook(WINDOW *win);
int ret_book(FORM *form, FIELD **field);
int searchbook(WINDOW *win);
int search(WINDOW *win, int m);
int show(WINDOW *win_2, char *s, int m);

int rows, cols, i;
WINDOW *my_menu_win, *win_1, *win, *win_2;
char issuedate[10];
