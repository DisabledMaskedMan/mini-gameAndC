#define MAX 1000

#define NAME_MAX 20
#define SEX_MAX 5
#define ADDR_MAX 30
#define TELE_MAX 12


#include <stdio.h>
#include <string.h>

struct Userinf
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char addr[ADDR_MAX];
	char tele[TELE_MAX];
};

struct Contact
{
	struct Userinf data[MAX];
	int size;
};

enum option
{
	Exit,
	Add,
	Del,
	Modify,
	Show,
	Search,
	Sort
};

void Initcontact(struct Contact* ps);
void ADD_CONTACT(struct Contact* ps);
void DELETE_CONTACT(struct Contact* ps);
void MODIFY_CONTACT(struct Conatct* ps);
void SHOW_CONTACT(struct Contact* ps);
void SEARCH_CONTACT(struct Contact* ps);
void SORT_CONTACT(struct Contact* ps);