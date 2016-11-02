/*****************************************************************************
 * Copyright (C) MOKSHADA MUNDHADA mokshada.mundhada@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 *****************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<menu.h>
#include<form.h>
#include<ctype.h>
#include"functions.h"
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

int main() {
	int ch;
	char *choices[] = {"MAIN MENU", "EXIT", (char *)NULL};
	ITEM **my_items;
	int c;				
	MENU *my_menu;
        WINDOW *my_menu_win;
        int n_choices;
	
	/* Initialize curses */
	initscr();
	start_color();
	getmaxyx(stdscr, rows, cols);
        cbreak();
        noecho();
	keypad(stdscr, TRUE);
	bkgd(0);
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);
	init_pair(3, COLOR_GREEN, COLOR_WHITE);
	init_pair(4, COLOR_RED, COLOR_CYAN);
	init_pair(5, COLOR_RED, COLOR_WHITE);
	attron(A_BOLD | A_UNDERLINE| COLOR_PAIR(1) | A_STANDOUT | A_BLINK);
	mvprintw(4, (cols - 36)/2, "WELCOME TO LIBRARY MANAGEMENT SYSTEM");
	mvprintw(rows - 5, (cols - 36)/2, "Created by : MOKSHADA MUNDHADA");
	mvprintw(rows - 4, (cols - 36)/2, "MIS NO. : 111508052");
	mvprintw(rows - 3, (cols - 36)/2, "Email id : mokshada.mundhada@gmail.com");
	attroff(A_BOLD | A_UNDERLINE | COLOR_PAIR(1) | A_STANDOUT | A_BLINK);
	refresh();
	
	win_1 = newwin(10, 50, (rows - 10)/2, (cols - 50)/2);
	box(win_1, 0, 0);
	wbkgd(win_1, COLOR_PAIR(3));
	wrefresh(win_1);
	
	/* Create items */
        n_choices = ARRAY_SIZE(choices);
	my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
        for(i = 0; i < n_choices; ++i) 
                my_items[i] = new_item(choices[i], choices[i]);
	my_items[i]=(ITEM *)NULL;	
	/*menu */
	my_menu = new_menu((ITEM **)my_items);
	/* Set menu option*/
	menu_opts_off(my_menu, O_SHOWDESC);
        keypad(win_1, TRUE);
	set_menu_win(my_menu, win_1);
        set_menu_sub(my_menu, derwin(win_1, 7, 38, 3, 1));
	set_menu_format(my_menu, 4, 1);
	set_menu_mark(my_menu, " -> ");
	set_menu_fore(my_menu,COLOR_PAIR(2));
	set_menu_back(my_menu,COLOR_PAIR(3));
	set_menu_grey(my_menu,COLOR_PAIR(3));
	print_in_middle(win_1, 1, 0, 50, "LIBRARY MANAGEMENT SYSTEM", COLOR_PAIR(3) | A_REVERSE);
	post_menu(my_menu);
	wrefresh(win_1);
	attron(COLOR_PAIR(1) | A_BOLD);
	mvprintw(rows - 1, 0, "Arrow Keys to navigate. ENTER to select");
	attroff(COLOR_PAIR(1) | A_BOLD);
	refresh();
	wrefresh(win_1);
	while((c = wgetch(win_1)) != KEY_F(3))
	{       
		switch(c)
	        {	case KEY_DOWN:
				menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;
			
			case 10:
				if(strcmp(item_name(current_item(my_menu)),"MAIN MENU") == 0 ) {
					mainmenu(win_1);
					unpost_menu(my_menu);
        				free_menu(my_menu);
        				for(i = 0; i < n_choices; ++i)
                				free_item(my_items[i]);					
				}

				else if(strcmp(item_name(current_item(my_menu)),"EXIT") == 0 ) {
						endwin();
						exit(0);
						return 0;
				}
				break;
		}
                wrefresh(win_1);
	}	
	end:
	/* Unpost and free all the memory taken up */
	unpost_menu(my_menu);
        free_menu(my_menu);
        for(i = 0; i < n_choices; ++i)
                free_item(my_items[i]);
	endwin();
	return 0;
}

////////////////////////////////////////////////////////////MAINMENU////////////////////////////////////////////////////////

int mainmenu(WINDOW *my_win) {
	char *choices[] = {"Add Books", "Delete Books", "Search Books", "Issue Books Section", "Edit Record", "Membership", "View Books", "Home", (char*)NULL};
	ITEM **my_items;
	int c;				
	MENU *my_menu;
       
        int n_choices;
        win_1 = newwin(20, 80, (rows - 20)/2, (cols - 80)/2);
	box(win_1, 0, 0);
	wbkgd(win_1, COLOR_PAIR(3));
	wrefresh(win_1);
	/* Create items */
        n_choices = ARRAY_SIZE(choices);
	my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
        for(i = 0; i < n_choices; ++i) 
                my_items[i] = new_item(choices[i], choices[i]);
	my_items[i]=(ITEM *)NULL;	
	/*menu */
	my_menu = new_menu((ITEM **)my_items);
	/* Set menu option*/
	menu_opts_off(my_menu, O_SHOWDESC);
        keypad(win_1, TRUE);
	set_menu_win(my_menu, win_1);
        set_menu_sub(my_menu, derwin(win_1, 12, 50, 8, 15));
	set_menu_format(my_menu, 4, 2);
	set_menu_mark(my_menu, " -> ");
	set_menu_fore(my_menu,COLOR_PAIR(2));
	set_menu_back(my_menu,COLOR_PAIR(3));
	set_menu_grey(my_menu,COLOR_PAIR(3));
	print_in_middle(win_1, 1, 0, 80, "LIBRARY MANAGEMENT SYSTEM", COLOR_PAIR(3) | A_REVERSE);
	post_menu(my_menu);
	wrefresh(win_1);
	while((c = wgetch(win_1)) != KEY_F(3))
	{       
		switch(c)
	        {	case KEY_DOWN:
				menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;
			case KEY_LEFT:
				menu_driver(my_menu, REQ_LEFT_ITEM);
				break;
			case KEY_RIGHT:
				menu_driver(my_menu, REQ_RIGHT_ITEM);
				break;
			
			case 10:
				if(strcmp(item_name(current_item(my_menu)),"Add Books") == 0 ) {
                			window_1(win, 1);
				}
				
				if(strcmp(item_name(current_item(my_menu)),"Search Books") == 0 ) {
					window_2(win, 2);
				}

				if(strcmp(item_name(current_item(my_menu)),"Membership") == 0 ) {
					window_2(win, 0);
				}
				
				if(strcmp(item_name(current_item(my_menu)),"Issue Books Section") == 0 ) {
					window_2(win, 1);
				}
				
				if(strcmp(item_name(current_item(my_menu)), "Home") == 0) {
					main();
				} 
				
				break;
		}
                wrefresh(win_1);
	}	
	end:
	/* Unpost and free all the memory taken up */
	unpost_menu(my_menu);
        free_menu(my_menu);
        for(i = 0; i < n_choices; ++i)
                free_item(my_items[i]);
        endwin();
        return 0;
}

///////////////////////////////////////////////////////ADD NEW BOOKS IN LIBRARY////////////////////////////////////////////////		

int addbook(WINDOW *win) {
	FIELD **field;
	FORM *form;
	int ch = 0, i = 0, j = 0, x, y, size, flag = 0, c = 0;
	char *str; 
	char *field_names[] = {"BOOK ID", "BOOK NAME","BOOK AUTHOR","BOOK CATEGORY","PRICE","QUANTITY"};
	str = (char *)malloc(sizeof(char) * 31);
	while(j< 30){
		str[j] = ' ';
		j++;
	}
	str[j] = '\0';
	size = sizeof(field_names) / sizeof(field_names[0]);
	cbreak();
	keypad(win, TRUE);
	field = (FIELD**)malloc((size + 2) * sizeof(FIELD*));
	for(i = 0; i < 6; i++) {
		field[i] = new_field(1, 25, 5 + 2 * i, 50, 0, 0);
	}
	i = 0;
	while(i < size) {
		field_opts_off(field[i], O_AUTOSKIP);
		set_field_back(field[i], COLOR_PAIR(5));
		i++;
	}
	
	field[6] = new_field(1, 6, 18, 30, 0, 0);
	field_opts_off(field[6], O_AUTOSKIP | O_EDIT);
	set_field_back(field[6], COLOR_PAIR(5));
	set_field_fore(field[6], COLOR_PAIR(5));
	set_field_buffer(field[6], 0, "ADD");
	
	field[7] = new_field(1, 7, 18, 50, 0, 0);
	field_opts_off(field[7], O_AUTOSKIP | O_EDIT);
	set_field_back(field[7], COLOR_PAIR(5));
	set_field_fore(field[7], COLOR_PAIR(5));
	set_field_buffer(field[7], 0, "EXIT");
	
	field[8] = NULL;
	form = new_form(field);
	scale_form(form, &y, &x);
	set_form_win(form, win);
	set_form_sub(form, derwin(win, y, x, 2, 40));
	post_form(form);
	
	for(i = 0; i < 6; i++)
		mvwprintw(win, 5 + 2 * i, 20, "%s : ", field_names[i]);
	mvwprintw(win, 1, 35, "ADD NEW BOOK", A_BOLD | COLOR_PAIR(4) | A_REVERSE);
	print_in_middle(win, 20, 0, 80,"USE UP AND DOWN KEYS TO MOVE BETWEEN FIELDS", COLOR_PAIR(5));
	
	form_driver(form, REQ_FIRST_FIELD);
	wrefresh(win);
	
	while(i = wgetch(win)) {
		if(isprint(i) || (i == ' ') || (i == '\t') )
			form_driver(form, i);
		else {
			switch(i) {
				case KEY_DOWN:
					form_driver(form, REQ_NEXT_FIELD);
					form_driver(form, REQ_END_LINE);
					break;
				case KEY_UP:
					form_driver(form, REQ_PREV_FIELD);
					form_driver(form, REQ_END_LINE);
					break;
				case KEY_LEFT:
					form_driver(form, REQ_PREV_CHAR);
					break;
				case KEY_RIGHT:
					form_driver(form, REQ_NEXT_CHAR);
					break;
				case 27:
					goto end;
					break;
				case KEY_BACKSPACE: case 127:
					form_driver(form, REQ_DEL_PREV);
					break;
				case KEY_DC:
					form_driver(form, REQ_DEL_CHAR);
					break;
				case 10:
					if(field[5] == current_field(form)) {
						flag = 0;						
						i = 0;
						while(i < 5) {
							if(strcmp(field_buffer(field[i], 0), str) == 0 ) {
								mvwprintw(win, 19, 40, "Field can't be empty", COLOR_PAIR(5));
								flag = 1;
								break;
							}
							i++;
						}
						if(flag == 0) {
							c = add_to_file(form, field);
							if(c == 0)
								mvwprintw(win, 19, 44, "ID already exists", COLOR_PAIR(5));
							else
								mvwprintw(win, 19, 40, "Book Added successfully", COLOR_PAIR(5));
							i = 0;
							while( i < size ) 
								set_field_buffer(field[i++], 0, "");
						}
							form_driver(form, REQ_FIRST_FIELD);
					}
					
					else if(field[7] == current_field(form)) {
						mainmenu(win_1);
					}
					else {
						form_driver(form, REQ_NEXT_FIELD);
						form_driver(form, REQ_END_LINE);
					}
					break;
				default:
					getyx(win, y, x);
					mvwprintw(win, 19, 40, "Character not allowed", COLOR_PAIR(5));
					wmove(win, y, x);
					break;
			}
		}
	}
	end:
	unpost_form(form);
	free_form(form);
	wclear(win);
	i = 0;
	while(i < size) {
		wmove(win, 3 + 2 * i, 1);
		wclrtoeol(win);
		free_field(field[i]);
		i++;
	}
	free(field);
	box(win, 0, 0);
	wrefresh(win);
	free(str);
}

		
// to add to file
int add_to_file(FORM *form, FIELD **field){
	FILE *fp;
	int  i = 0, j = 0, k = 0;
	int len = field_count(form);
	char **ch;
	char *ch1;
	ch = (char **)malloc(sizeof(char *) * len);
	book b1, b2;
	fp = fopen("bookrecord.txt", "a+");
	while(i < len){
		ch[i] = field_buffer(field[i], 0);
		i++;
	}
	ch1 = string(ch[0]);
	b2.id = atoi(ch1);
	
	while(fscanf(fp, "%d %s %s %s %f %d", &b1.id, b1.name, b1.author, b1.cat, &b1.price, &b1.quantity) != EOF) {
		if(b2.id == b1.id)
			return 0;
		else if(feof(fp))
			break;
	}
	ch1 = string(ch[1]);
	strcpy(b2.name, ch1);
	ch1 = string(ch[2]);
	strcpy(b2.author, ch1);
	ch1 = string(ch[3]);
	strcpy(b2.cat, ch1);
	ch1 = string(ch[4]);
	b2.price = atof(ch1);
	ch1 = string(ch[5]);
	b2.quantity = atoi(ch1);
	
	fprintf(fp, "\n%d \t %s \t %s \t %s \t %f \t %d", b2.id, b2.name, b2.author, b2.cat, b2.price, b2.quantity);
	free(ch);
	fclose(fp);
	return 1;
}

/////////////////////////////////////////////////conversion of entered data//////////////////////////////////////////////////////

char *string(char *ch) {
	int i = 0;
	char *s;
	s = (char *)malloc(sizeof(char) * 30);
	while(ch[i] != 32) {
		s[i] = ch[i];
		i++;
	}
	s[i] = '\0';
	return s;
}

//////////////////////////////////////////////////////////MEMBERSHIP MENU///////////////////////////////////////////////////////////////// 

int mem(WINDOW *win) {
	char *choices[] = {"ADD MEMBER", "DELETE MEMBER", "VIEW MEMBER RECORDS", "HOME", (char*)NULL};
	int m, x, y;
	ITEM **my_items;
	MENU *my_menu;
	int n_choices = ARRAY_SIZE(choices);
	my_items = (ITEM**)calloc(n_choices, sizeof(ITEM*));
	for(i = 0; i < n_choices; ++i)
		 my_items[i] = new_item(choices[i], choices[i]);
	my_items[i]=(ITEM *)NULL;	
	/*menu */
	my_menu = new_menu((ITEM **)my_items);
	/* Set menu option*/
	menu_opts_off(my_menu, O_SHOWDESC);
        keypad(win, TRUE);
	set_menu_win(my_menu, win);
        set_menu_sub(my_menu, derwin(win, 13, 50, 7, 15));
	set_menu_format(my_menu, 4, 1);
	set_menu_mark(my_menu, " -> ");
	set_menu_fore(my_menu,COLOR_PAIR(2));
	set_menu_back(my_menu,COLOR_PAIR(3));
	set_menu_grey(my_menu,COLOR_PAIR(3));
	print_in_middle(win, 1, 0, 80, "MEMBERSHIP", COLOR_PAIR(3) | A_REVERSE);
	post_menu(my_menu);
	wrefresh(win);
	while((m = wgetch(win)) != KEY_F(3))
	{       
		switch(m)
	        {	case KEY_DOWN:
				menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;
			
			case 10:
				if(strcmp(item_name(current_item(my_menu)),"ADD MEMBER") == 0 ) {
					window_1(win, 4);
					unpost_menu(my_menu);
        					free_menu(my_menu);
       						 for(i = 0; i < n_choices; ++i)
                					free_item(my_items[i]);	
				}
				
				else if(strcmp(item_name(current_item(my_menu)), "DELETE MEMBER") == 0) {
					
				} 
				else if(strcmp(item_name(current_item(my_menu)), "VIEW MEMBER RECORDS")) {
				}
				
				else if(strcmp(item_name(current_item(my_menu)),"HOME") == 0 ) {
					mainmenu(win_1);
				}
				break;
		}
                wrefresh(win);
	}	
	end:
	/* Unpost and free all the memory taken up */
	unpost_menu(my_menu);
        free_menu(my_menu);
        for(i = 0; i < n_choices; ++i)
                free_item(my_items[i]);
	endwin();
	return 0;
}

//add new member
	
int addmem(WINDOW *win) {
	FIELD **field;
	FORM *form;
	int ch = 0, i = 0, j = 0, x, y, size, flag = 0, c = 0;
	char *str; 
	char *field_names[] = {"MEMBER ID", "MEMBER NAME","MEMBER CONTACT", "MEMBER EMAIL-ID", "DATE", (char*)NULL};
	str = (char *)malloc(sizeof(char) * 31);
	while(j< 30){
		str[j] = ' ';
		j++;
	}
	str[j] = '\0';
	size = sizeof(field_names) / sizeof(field_names[0]);
	cbreak();
	keypad(win, TRUE);
	field = (FIELD**)malloc((size + 2) * sizeof(FIELD*));
	for(i = 0; i < 5; i++) {
		field[i] = new_field(1, 30, 5 + 2 * i, 45, 0, 0);
	}
	i = 0;
	while(i < size) {
		field_opts_off(field[i], O_AUTOSKIP);
		set_field_back(field[i], COLOR_PAIR(5));
		i++;
	}
	
	field[5] = new_field(1, 4, 17, 30, 0, 0);
	field_opts_off(field[5], O_AUTOSKIP | O_EDIT);
	set_field_back(field[5], COLOR_PAIR(5));
	set_field_fore(field[5], COLOR_PAIR(5));
	set_field_buffer(field[5], 0, "ADD");
	
	field[6] = new_field(1, 6, 17, 50, 0, 0);
	field_opts_off(field[6], O_AUTOSKIP | O_EDIT);
	set_field_back(field[6], COLOR_PAIR(5));
	set_field_fore(field[6], COLOR_PAIR(5));
	set_field_buffer(field[6], 0, "EXIT");
	
	field[7] = NULL;
	form = new_form(field);
	scale_form(form, &y, &x);
	set_form_win(form, win);
	set_form_sub(form, derwin(win, y, x, 2, 40));
	post_form(form);
	
	for(i = 0; i < 5; i++)
		mvwprintw(win, 5 + 2 * i, 20, "%s : ", field_names[i]);
	mvwprintw(win, 1, 35, "ADD NEW MEMBER", A_BOLD | COLOR_PAIR(4) | A_REVERSE);
	form_driver(form, REQ_FIRST_FIELD);
	wrefresh(win);
	
	while(i = wgetch(win)) {
		if(isprint(i) || (i == ' ') || (i == '\t') )
			form_driver(form, i);
		else {
			switch(i) {
				case KEY_DOWN:
					form_driver(form, REQ_NEXT_FIELD);
					form_driver(form, REQ_END_LINE);
					break;
				case KEY_UP:
					form_driver(form, REQ_PREV_FIELD);
					form_driver(form, REQ_END_LINE);
					break;
				case KEY_LEFT:
					form_driver(form, REQ_PREV_CHAR);
					break;
				case KEY_RIGHT:
					form_driver(form, REQ_NEXT_CHAR);
					break;
				case 27:
					goto end;
					break;
				case KEY_BACKSPACE: case 127:
					form_driver(form, REQ_DEL_PREV);
					break;
				case KEY_DC:
					form_driver(form, REQ_DEL_CHAR);
					break;
				case 10:
					if(field[5] == current_field(form)) {
						flag = 0;						
						i = 0;
						while(i < 5) {
							if(strcmp(field_buffer(field[i], 0), str) == 0 ) {
								mvwprintw(win, 19, 40, "Field can't be empty", COLOR_PAIR(5));
								flag = 1;
								break;
							}
							i++;
						}
						if(flag == 0) {
							c = addmem_to_file(form, field);
							if(c == 0)
								mvwprintw(win, 19, 40, "ID ALREADY EXISTS", COLOR_PAIR(5));
							else
								mvwprintw(win, 19, 40, "Member Added successfully", COLOR_PAIR(5));
							i = 0;
							while( i < size ) 
								set_field_buffer(field[i++], 0, "");
						}
							form_driver(form, REQ_FIRST_FIELD);
					}
					
					else if(field[6] == current_field(form)) {
						mainmenu(win_1);
					}
					else {
						form_driver(form, REQ_NEXT_FIELD);
						form_driver(form, REQ_END_LINE);
					}
					break;
				default:
					getyx(win, y, x);
					mvwprintw(win, 19, 40, "Character not allowed", COLOR_PAIR(5));
					wmove(win, y, x);
					break;
			}
		}
	}
	end:
	unpost_form(form);
	free_form(form);
	wclear(win);
	i = 0;
	while(i < size) {
		wmove(win, 3 + 2 * i, 1);
		wclrtoeol(win);
		free_field(field[i]);
		i++;
	}
	free(field);
	box(win, 0, 0);
	wrefresh(win);
	free(str);
}

//add member to file

int addmem_to_file(FORM *form, FIELD **field) {
	FILE *fp;
	int  i = 0, j = 0, k = 0;
	int len = field_count(form);
	char **ch;
	char *ch1;
	ch = (char **)malloc(sizeof(char *) * len);
	fp = fopen("memberrecord.txt", "a+");
	while(i < len){
		ch[i] = field_buffer(field[i], 0);
		i++;
	}
	ch1 = string(ch[0]);
	m2.id = atoi(ch1);
	while(fscanf(fp, "%d %s %ld %s %s %d", &m1.id, m1.name, &m1.contact, m1.emailid, m1.joindate, &m1.availablecards) != EOF) {
		if(m2.id == m1.id)
			return 0;
		else if(feof(fp))
			break;
	}
	m1.id = m2.id;
	ch1 = string(ch[1]);
	strcpy(m1.name, ch1);
	ch1 = string(ch[2]);
	m1.contact = atol(ch1);
	ch1 = string(ch[3]);
	strcpy(m1.emailid, ch1);
	ch1 = string(ch[4]);
	strcpy(m1.joindate, ch1);
	m1.availablecards = 30;
	fprintf(fp, "\n%d \t %s \t %ld \t %s \t %s \t %d", m1.id, m1.name, m1.contact, m1.emailid, m1.joindate, m1.availablecards);
	free(ch);
	fclose(fp);
	return 1;
}

/////////////////////////////////////////////////////ISSUE SECTION ///////////////////////////////////////////////////////////////////////

int issuesection(WINDOW *win) {
	char *choices[] = {"ISSUE BOOK", "RETURN BOOK",  "EXIT", (char*)NULL};
	int c, x, y;
	ITEM **my_items;
	MENU *my_menu;
	int n_choices = ARRAY_SIZE(choices);
	my_items = (ITEM**)calloc(n_choices, sizeof(ITEM*));
	for(i = 0; i < n_choices; ++i)
		 my_items[i] = new_item(choices[i], choices[i]);
	my_items[i]=(ITEM *)NULL;	
	/*menu */
	my_menu = new_menu((ITEM **)my_items);
	/* Set menu option*/
	menu_opts_off(my_menu, O_SHOWDESC);
        keypad(win, TRUE);
	set_menu_win(my_menu, win);
        set_menu_sub(my_menu, derwin(win, 13, 50, 7, 15));
	set_menu_format(my_menu, 3, 1);
	set_menu_mark(my_menu, " -> ");
	set_menu_fore(my_menu,COLOR_PAIR(2));
	set_menu_back(my_menu,COLOR_PAIR(3));
	set_menu_grey(my_menu,COLOR_PAIR(3));
	print_in_middle(win, 1, 0, 80, "ISSUE BOOKS SECTION", COLOR_PAIR(3) | A_REVERSE);
	post_menu(my_menu);
	wrefresh(win);
	while((c = wgetch(win)) != KEY_F(3))
	{       
		switch(c)
	        {	case KEY_DOWN:
				menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;
			
			case 10:
				if(strcmp(item_name(current_item(my_menu)),"EXIT") == 0 ) {
					mainmenu(win_1);
					unpost_menu(my_menu);
        				free_menu(my_menu);
        				for(i = 0; i < n_choices; ++i)
                				free_item(my_items[i]);					
				}
				
				
				if(strcmp(item_name(current_item(my_menu)), "ISSUE BOOK") == 0) {
				window_1(win, 2);	
					
				} 
				else if(strcmp(item_name(current_item(my_menu)),"RETURN BOOK") == 0 ) {
				window_1(win, 3);
				}
				wrefresh(win);
				break;
               			
		}
	}	
	end:
	/* Unpost and free all the memory taken up */
	unpost_menu(my_menu);
        free_menu(my_menu);
        for(i = 0; i < n_choices; ++i)
                free_item(my_items[i]);
	endwin();
	return 0;
}

//issue books

int issue(WINDOW *win) {
	FIELD **field;
	FORM *form;
	int ch = 0, i = 0, j = 0, x, y, size, flag = 0, c = 0;
	char *str; 
	char *field_names[] = {"MEMBER ID", "BOOK ID", "ISSUE DATE", (char*)NULL};
	str = (char *)malloc(sizeof(char) * 31);
	while(j< 30){
		str[j] = ' ';
		j++;
	}
	str[j] = '\0';
	size = sizeof(field_names) / sizeof(field_names[0]);
	cbreak();
	keypad(win, TRUE);
	field = (FIELD**)malloc((size + 2) * sizeof(FIELD*));
	for(i = 0; i < 3; i++) {
		field[i] = new_field(1, 30, 5 + 2 * i, 45, 0, 0);
	}
	i = 0;
	while(i < size) {
		field_opts_off(field[i], O_AUTOSKIP);
		set_field_back(field[i], COLOR_PAIR(5));
		i++;
	}
	
	field[3] = new_field(1, 9, 17, 30, 0, 0);
	field_opts_off(field[3], O_AUTOSKIP | O_EDIT);
	set_field_back(field[3], COLOR_PAIR(5));
	set_field_fore(field[3], COLOR_PAIR(5));
	set_field_buffer(field[3], 0, "ISSUE");
	
	field[4] = new_field(1, 8, 17, 50, 0, 0);
	field_opts_off(field[4], O_AUTOSKIP | O_EDIT);
	set_field_back(field[4], COLOR_PAIR(5));
	set_field_fore(field[4], COLOR_PAIR(5));
	set_field_buffer(field[4], 0, "EXIT");
	
	field[5] = NULL;
	form = new_form(field);
	scale_form(form, &y, &x);
	set_form_win(form, win);
	set_form_sub(form, derwin(win, y, x, 2, 40));
	post_form(form);
	
	for(i = 0; i < 3; i++)
		mvwprintw(win, 5 + 2 * i, 20, "%s : ", field_names[i]);
	mvwprintw(win, 1, 35, "ISSUE BOOK", A_BOLD | COLOR_PAIR(4) | A_REVERSE);
	form_driver(form, REQ_FIRST_FIELD);
	wrefresh(win);
	
	while(i = wgetch(win)) {
		if(isprint(i) || (i == ' ') || (i == '\t') )
			form_driver(form, i);
		else {
			switch(i) {
				case KEY_DOWN:
					form_driver(form, REQ_NEXT_FIELD);
					form_driver(form, REQ_END_LINE);
					break;
				case KEY_UP:
					form_driver(form, REQ_PREV_FIELD);
					form_driver(form, REQ_END_LINE);
					break;
				case KEY_LEFT:
					form_driver(form, REQ_PREV_CHAR);
					break;
				case KEY_RIGHT:
					form_driver(form, REQ_NEXT_CHAR);
					break;
				case 27:
					goto end;
					break;
				case KEY_BACKSPACE: case 127:
					form_driver(form, REQ_DEL_PREV);
					break;
				case KEY_DC:
					form_driver(form, REQ_DEL_CHAR);
					break;
				case 10:
					if(field[3] == current_field(form)) {
						flag = 0;						
						i = 0;
						while(i < 3) {
							if(strcmp(field_buffer(field[i], 0), str) == 0 ) {
								mvwprintw(win, 19, 40,"Field can't be empty", COLOR_PAIR(5));
								flag = 1;
								break;
							}
							i++;
						}
						if(flag == 0) {
							c = issuerecord_to_file(form, field);
							if(c == 0)
								mvwprintw(win, 19, 40, "Check your details again", COLOR_PAIR(5));
							else
								mvwprintw(win, 19, 40, "Book Issued successfully", COLOR_PAIR(5));
							i = 0;
							while( i < size ) 
								set_field_buffer(field[i++], 0, "");
						}
							form_driver(form, REQ_FIRST_FIELD);
					}
					
					else if(field[4] == current_field(form)) {
						mainmenu(win_1);
					}
					else {
						form_driver(form, REQ_NEXT_FIELD);
						form_driver(form, REQ_END_LINE);
					}
					break;
				default:
					getyx(win, y, x);
					mvwprintw(win, 19, 40, "Character not allowed", COLOR_PAIR(5));
					wmove(win, y, x);
					break;
			}
		}
	}
	end:
	unpost_form(form);
	free_form(form);
	wclear(win);
	i = 0;
	while(i < size) {
		wmove(win, 3 + 2 * i, 1);
		wclrtoeol(win);
		free_field(field[i]);
		i++;
	}
	free(field);
	box(win, 0, 0);
	wrefresh(win);
	free(str);
}

//store issued record in file 

int issuerecord_to_file(FORM *form, FIELD **field) {
	FILE *fp, *fp1, *fp2, *temp;
	book b1, b2;
	int  i = 0, j = 0, status = 0;
	int len = field_count(form);
	char **ch;
	char *ch1;
	ch = (char **)malloc(sizeof(char *) * len);
	fp = fopen("issuerecord.txt", "a+");
	fp1 = fopen("memberrecord.txt", "r+");
	fp2 = fopen("bookrecord.txt", "r+");
	temp = fopen("temp.txt", "w+");
	while(i < len){
		ch[i] = field_buffer(field[i], 0);
		i++;
	}
	ch1 = string(ch[0]);
	m2.id = atoi(ch1);
	ch1 = string(ch[1]);
	b2.id = atoi(ch1);
	while(fscanf(fp1, "%d %s %ld %s %s %d", &m1.id, m1.name, &m1.contact, m1.emailid, m1.joindate, &m1.availablecards) != EOF) {
		if(m2.id == m1.id) {
			if(m1.availablecards < 1) 
				return 0;
			else 
				break;
		}
	}
	while(fscanf(fp2, "%d %s %s %s %f %d", &b1.id, b1.name, b1.author, b1.cat, &b1.price, &b1.quantity) != EOF) {
		if(b2.id == b1.id) 
			j =1;
	}
	if(j == 1) {
		ch1 = string(ch[2]);
		strcpy(issuedate, ch1);
		status = 1;
		fprintf(fp, "\n%d \t %d \t %s \t %d", m2.id, b2.id, issuedate, status);
	}
	else 
		return 0;
	m1.availablecards--;
	fprintf(temp, "\n%d \t %s \t %ld \t %s \t %s \t %d", m1.id, m1.name, m1.contact, m1.emailid, m1.joindate, m1.availablecards);
	free(ch);
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
	fclose(temp);
	remove("memberrecord.txt");
	rename("temp.txt", "memberrecord.txt");
	return 1;
}

//return book 

int returnbook(WINDOW *win) {
	FIELD **field;
	FORM *form;
	int ch = 0, i = 0, j = 0, x, y, size, flag = 0, c = 0;
	char *str; 
	char *field_names[] = {"MEMBER ID", "BOOK ID", (char*)NULL};
	str = (char *)malloc(sizeof(char) * 31);
	while(j< 30){
		str[j] = ' ';
		j++;
	}
	str[j] = '\0';
	size = sizeof(field_names) / sizeof(field_names[0]);
	cbreak();
	keypad(win, TRUE);
	field = (FIELD**)malloc((size + 2) * sizeof(FIELD*));
	for(i = 0; i < 2; i++) {
		field[i] = new_field(1, 30, 5 + 2 * i, 45, 0, 0);
	}
	i = 0;
	while(i < size) {
		field_opts_off(field[i], O_AUTOSKIP);
		set_field_back(field[i], COLOR_PAIR(5));
		i++;
	}
	
	field[2] = new_field(1, 15, 17, 30, 0, 0);
	field_opts_off(field[2], O_AUTOSKIP | O_EDIT);
	set_field_back(field[2], COLOR_PAIR(5));
	set_field_fore(field[2], COLOR_PAIR(5));
	set_field_buffer(field[2], 0, "RETURN BOOK");
	
	field[3] = new_field(1, 6, 17, 50, 0, 0);
	field_opts_off(field[3], O_AUTOSKIP | O_EDIT);
	set_field_back(field[3], COLOR_PAIR(5));
	set_field_fore(field[3], COLOR_PAIR(5));
	set_field_buffer(field[3], 0, "EXIT");
	
	field[4] = NULL;
	form = new_form(field);
	scale_form(form, &y, &x);
	set_form_win(form, win);
	set_form_sub(form, derwin(win, y, x, 2, 40));
	post_form(form);
	
	for(i = 0; i < 2; i++)
		mvwprintw(win, 5 + 2 * i, 20, "%s : ", field_names[i]);
	mvwprintw(win, 1, 30, "RETURN ISSUED BOOK", A_BOLD | COLOR_PAIR(4) | A_REVERSE);
	form_driver(form, REQ_FIRST_FIELD);
	wrefresh(win);
	
	while(i = wgetch(win)) {
		if(isprint(i) || (i == ' ') || (i == '\t') )
			form_driver(form, i);
		else {
			switch(i) {
				case KEY_DOWN:
					form_driver(form, REQ_NEXT_FIELD);
					form_driver(form, REQ_END_LINE);
					break;
				case KEY_UP:
					form_driver(form, REQ_PREV_FIELD);
					form_driver(form, REQ_END_LINE);
					break;
				case KEY_LEFT:
					form_driver(form, REQ_PREV_CHAR);
					break;
				case KEY_RIGHT:
					form_driver(form, REQ_NEXT_CHAR);
					break;
				case 27:
					goto end;
					break;
				case KEY_BACKSPACE: case 127:
					form_driver(form, REQ_DEL_PREV);
					break;
				case KEY_DC:
					form_driver(form, REQ_DEL_CHAR);
					break;
				case 10:
					if(field[2] == current_field(form)) {
						flag = 0;						
						i = 0;
						while(i < 2) {
							if(strcmp(field_buffer(field[i], 0), str) == 0 ) {
								mvwprintw(win, 19, 35,"Field can't be empty", COLOR_PAIR(5));
								flag = 1;
								break;
							}
							i++;
						}
						if(flag == 0) {
							c = ret_book(form, field);
							if(c == 0)
								mvwprintw(win, 19, 35, "Check your details again", COLOR_PAIR(5));
							else
								mvwprintw(win, 19, 35, "Book Issued successfully", COLOR_PAIR(5));
							i = 0;
							while( i < size ) 
								set_field_buffer(field[i++], 0, "");
						}
							form_driver(form, REQ_FIRST_FIELD);
					}
					
					else if(field[3] == current_field(form)) {
						mainmenu(win_1);
					}
					else {
						form_driver(form, REQ_NEXT_FIELD);
						form_driver(form, REQ_END_LINE);
					}
					break;
				default:
					getyx(win, y, x);
					mvwprintw(win, 19, 35, "Character not allowed", COLOR_PAIR(5));
					wmove(win, y, x);
					break;
			}
		}
	}
	end:
	unpost_form(form);
	free_form(form);
	wclear(win);
	i = 0;
	while(i < size) {
		wmove(win, 3 + 2 * i, 1);
		wclrtoeol(win);
		free_field(field[i]);
		i++;
	}
	free(field);
	box(win, 0, 0);
	wrefresh(win);
	free(str);
}

//store returned book record in file

int ret_book(FORM *form, FIELD **field) {
	FILE *fp, *fp1, *fp2, *temp;
	book b1, b2;
	int  i = 0, j = 0, status = 0;
	int len = field_count(form);
	char **ch;
	char *ch1;
	ch = (char **)malloc(sizeof(char *) * len);
	fp = fopen("issuerecord.txt", "a+");
	fp1 = fopen("memberrecord.txt", "r+");
	fp2 = fopen("bookrecord.txt", "r+");
	temp = fopen("temp.txt", "w+");
	while(i < len){
		ch[i] = field_buffer(field[i], 0);
		i++;
	}
	ch1 = string(ch[0]);
	m2.id = atoi(ch1);
	ch1 = string(ch[1]);
	b2.id = atoi(ch1);
	while(fscanf(fp1, "%d %s %ld %s %s %d", &m1.id, m1.name, &m1.contact, m1.emailid, m1.joindate, &m1.availablecards) != EOF) {
		if(m2.id == m1.id) 
			break; 
		else 
			return 0;
	}
	while(fscanf(fp2, "%d %s %s %s %f %d", &b1.id, b1.name, b1.author, b1.cat, &b1.price, &b1.quantity) != EOF) {
		if(b2.id == b1.id) 
			break;
		else 
			return 0;
	}
			
	while(fscanf(fp, "%d %d %s %d", &m1.id, &b1.id, issuedate, &status) != EOF) {
		if(m2.id == m1.id) {
			if(m1.availablecards >= 30)
				return 0;
			else 
				break; 
		}
		if(b2.id == b1.id) 
			j = 1;
	}
	if(j == 1) 
		status = 0;
	fprintf(temp, "\n%d \t %d \t %s \t %d", m1.id, b1.id, issuedate, status);
	free(ch);
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
	fclose(temp);
	remove("issuerecord.txt");
	rename("temp.txt", "issuerecord.txt");
	return 1;
}

/////////////////////////////////////////////////////SEARCH BOOKS//////////////////////////////////////////////////////

int searchbook(WINDOW *win) {
	char *choices[] = {"Search by ID", "Search by Name",  "Search by Author", "Search by Category", "EXIT", (char*)NULL};
	int c, x, y;
	ITEM **my_items;
	MENU *my_menu;
	int n_choices = ARRAY_SIZE(choices);
	my_items = (ITEM**)calloc(n_choices, sizeof(ITEM*));
	for(i = 0; i < n_choices; ++i)
		 my_items[i] = new_item(choices[i], choices[i]);
	my_items[i]=(ITEM *)NULL;	
	/*menu */
	my_menu = new_menu((ITEM **)my_items);
	/* Set menu option*/
	menu_opts_off(my_menu, O_SHOWDESC);
        keypad(win, TRUE);
	set_menu_win(my_menu, win);
        set_menu_sub(my_menu, derwin(win, 13, 36, 7, 22));
	set_menu_format(my_menu, 5, 1);
	set_menu_mark(my_menu, " -> ");
	set_menu_fore(my_menu,COLOR_PAIR(2));
	set_menu_back(my_menu,COLOR_PAIR(3));
	set_menu_grey(my_menu,COLOR_PAIR(3));
	print_in_middle(win, 1, 0, 80, "SEARCH BOOKS", COLOR_PAIR(3) | A_REVERSE);
	post_menu(my_menu);
	wrefresh(win);
	while((c = wgetch(win)) != KEY_F(3))
	{       
		switch(c)
	        {	case KEY_DOWN:
				menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;
			
			case 10:
				if(strcmp(item_name(current_item(my_menu)),"EXIT") == 0 ) {
					mainmenu(win_1);
					unpost_menu(my_menu);
        				free_menu(my_menu);
        				for(i = 0; i < n_choices; ++i)
                				free_item(my_items[i]);					
				}
				
				
				if(strcmp(item_name(current_item(my_menu)), "Search by ID") == 0) {
					search(win, 0);	
				} 
				else if(strcmp(item_name(current_item(my_menu)),"Search by Name") == 0 ) {
					search(win, 1);
				}
				else if(strcmp(item_name(current_item(my_menu)),"Search by Author") == 0) {
					search(win, 2);
				}
				else if(strcmp(item_name(current_item(my_menu)),"Search by Category") == 0) {
					search(win, 3);
				}
				wrefresh(win);
				break;
               			
		}
	}	
	end:
	/* Unpost and free all the memory taken up */
	unpost_menu(my_menu);
        free_menu(my_menu);
        for(i = 0; i < n_choices; ++i)
                free_item(my_items[i]);
	endwin();
	return 0;
}

int search(WINDOW *win, int m) {
	win = newwin(20, 80, (rows - 20)/2, (cols - 80)/2 );
	box(win, 0, 0);
	wbkgd(win, COLOR_PAIR(4));
	wrefresh(win);
	FIELD **field;
	FORM *form;
	int ch = 0, i = 0, j = 0, x, y, flag = 0, c = 0;
	char *str; 
	str = (char *)malloc(sizeof(char) * 31);
	while(j< 30){
		str[j] = ' ';
		j++;
	}
	str[j] = '\0';
	cbreak();
	keypad(win, TRUE);
	field = (FIELD**)malloc(2 * sizeof(FIELD*));
	field[0] = new_field(1, 20, 5, 30, 0, 0);
	field_opts_off(field[0], O_AUTOSKIP);
	set_field_back(field[0], COLOR_PAIR(5));
	set_field_fore(field[0], COLOR_PAIR(5));
	
	field[1] = new_field(1, 6, 8, 30, 0, 0);
	field_opts_off(field[1], O_AUTOSKIP | O_EDIT);
	set_field_back(field[1], COLOR_PAIR(5));
	set_field_fore(field[1], COLOR_PAIR(5));
	set_field_buffer(field[1], 0, "SEARCH");
	
	field[2] = new_field(1, 6, 8, 44, 0, 0);
	field_opts_off(field[2], O_AUTOSKIP | O_EDIT);
	set_field_back(field[2], COLOR_PAIR(5));
	set_field_fore(field[2], COLOR_PAIR(5));
	set_field_buffer(field[2], 0, "EXIT");
	
	field[3] = NULL;
	form = new_form(field);
	scale_form(form, &y, &x);
	set_form_win(form, win);
	set_form_sub(form, derwin(win, y, x, 2, 40));
	post_form(form);
	wrefresh(win);
	form_driver(form, REQ_FIRST_FIELD);
	
	while(i = wgetch(win)) {
		if(isprint(i) || (i == ' ') || (i == '\t') )
			form_driver(form, i);
		else {
			switch(i) {
				case KEY_DOWN:
					form_driver(form, REQ_NEXT_FIELD);
					form_driver(form, REQ_END_LINE);
					break;
				case KEY_UP:
					form_driver(form, REQ_PREV_FIELD);
					form_driver(form, REQ_END_LINE);
					break;
				case KEY_LEFT:
					form_driver(form, REQ_PREV_CHAR);
					break;
				case KEY_RIGHT:
					form_driver(form, REQ_NEXT_CHAR);
					break;
				case 27:
					goto end;
					break;
				case KEY_BACKSPACE: case 127:
					form_driver(form, REQ_DEL_PREV);
					break;
				case KEY_DC:
					form_driver(form, REQ_DEL_CHAR);
					break;
				case 10:
					if(field[1] == current_field(form)) {
						if(strcmp(field_buffer(field[0], 0), str) != 0 ) {
							c = show(win_2, field_buffer(field[0], 0), m);
							if(c == 0)
								mvwprintw(win, 15, 35, "Book not found", COLOR_PAIR(5));
					
						}
						set_field_buffer(field[0], 0, "");
					}
						
					
					else if(field[2] == current_field(form)) {
						unpost_form(form);
						free_form(form);
						wclear(win);
						wrefresh(win);
						mainmenu(win_1);
					}
					else {
						form_driver(form, REQ_NEXT_FIELD);
						form_driver(form, REQ_END_LINE);
					}
					break;
				default:
					getyx(win, y, x);
					mvwprintw(win, 19, 35, "Character not allowed", COLOR_PAIR(5));
					wmove(win, y, x);
					break;
			}
		}
	}
	end:
	unpost_form(form);
	free_form(form);
	wclear(win);
	i = 0;
	while(i < 1) {
		wmove(win, 3 + 2 * i, 1);
		wclrtoeol(win);
		free_field(field[i]);
		i++;
	}
	free(field);
	box(win, 0, 0);
	wrefresh(win);
	free(str);
}

int show(WINDOW *win_2, char *s, int m){
	win_2 = newwin(30, 100, (rows - 30)/2, (cols - 100)/2);	
	box(win_2, 0 , 0);
	init_pair(6, COLOR_MAGENTA, COLOR_WHITE);	
	wbkgd(win_2, COLOR_PAIR(6));
	wrefresh(win_2);
	FILE *fp;
	book b1;
	int ch = 0,i = 0, j = 1, l = 0, id, flag = 0;
	int place[]={4, 10, 35, 50, 80, 90};
	fp = fopen("bookrecord.txt", "r+");
	cbreak();
	keypad(win_2, TRUE);
	char *ch1 = string(s);
	l = strlen(ch1);
	while(fscanf(fp, "%d %s %s %s %f %d", &b1.id, b1.name, b1.author, b1.cat, &b1.price, &b1.quantity) != EOF) {
		if(m == 0) {
			id = atoi(ch1);
			if(id == b1.id)
				flag = 1;
			else
				return 0;
		}
		else if(m == 1) {
			if(strncmp(ch1, b1.name, l) == 0) 
				flag = 1;
			else
				return 0;
		}
		else if(m == 2) {
			if(strncmp(ch1, b1.author, l) == 0)
				flag = 1;
			else 
				return 0;
		}
		else if(m == 3) {
			if(strncmp(ch1, b1.cat, l) == 0)
				flag = 1;
			else 
				return 0;
		}
		if(flag == 1) {
			wattron(win_2,COLOR_PAIR(6) | A_BOLD);
			mvwprintw(win_2, j, place[0], "%d", b1.id);
			mvwprintw(win_2, j, place[1], "%s", b1.name);
			mvwprintw(win_2, j, place[2], "%s", b1.author);
			mvwprintw(win_2, j, place[3], "%s", b1.cat);
			mvwprintw(win_2, j, place[4], "%f", b1.price);
			mvwprintw(win_2, j, place[5], "%d", b1.quantity);
			wattroff(win_2,COLOR_PAIR(6) | A_BOLD);
			wrefresh(win_2);
			j++;
			flag = 0;
		}
		
	}
	fclose(fp);
	wclear(win);
	endwin();
}

////////////////////////////////////////////////////print in middle of the window/////////////////////////////////////////////

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 100;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	wattron(win, color);
	mvwprintw(win, y, x, "%s", string);
	wattroff(win, color);
	refresh();
}


////////////////////////////////////////////////////////////////creating new window///////////////////////////////////////////////

int window_1(WINDOW *win_1,int m){
	i=0;	
	win = newwin(20, 80, (rows - 20)/2, (cols - 80)/2);	
	box(win, 0 , 0);	
	wbkgd(win, COLOR_PAIR(4));	
	wrefresh(win);
	if (m == 1)							
		i = addbook(win);
	else if(m == 2)
		i = issue(win);
	else if(m == 3)
		i = returnbook(win);
	else if(m == 4)
		i = addmem(win);
	//else if(m == 5)
	wclear(win);
	wbkgd(win,COLOR_PAIR(4));
	wrefresh(win);
	delwin(win);
	return i;
}

int window_2(WINDOW *win, int m) {
	i = 0;
	win = newwin(20, 80, (rows - 20)/2, (cols - 80)/2);
	box(win, 0 , 0);	
	wbkgd(win, COLOR_PAIR(3));	
	wrefresh(win);
	if (m == 0)		
		i = mem(win);
	else if(m == 1)
		i = issuesection(win);
	else if(m == 2)
		i = searchbook(win);
	wclear(win);
	wbkgd(win,COLOR_PAIR(3));
	wrefresh(win);
	delwin(win);
	return i;
}

	

			
