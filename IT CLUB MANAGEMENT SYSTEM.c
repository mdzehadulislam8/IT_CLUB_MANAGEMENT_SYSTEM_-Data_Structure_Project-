#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX_MEMBERS 100
#define MAX_EVENTS 100
#define PASSWORD "ZEHAD"
typedef struct {
int id;
char name[50];
int age;
} Member;
typedef struct {
int id;
char name[50];
char date[20];
} Event;
Member members[MAX_MEMBERS];
int numMembers = 0;
Event events[MAX_EVENTS];
int numEvents = 0;
void playWrongPasswordSound() {
// Play the sound using Windows API
printf("\a"); // Produces a beep sound
}
void login() {
char password[50];
int attempts = 3;
while (attempts > 0) {
printf("\t\t\t\tGreen University Of Bangladesh (GUB)\n\n");
printf("\t\t\t\t IT Club Management System\n\n");
printf("Login...\n\n");
printf("Enter password: ");
// Read the password character by character without echoing to the console
int i = 0;
char ch;
while ((ch = getch()) != '\r') { // '\r' is the enter key
if (ch == '\b') { // '\b' is the backspace key
if (i > 0) {
i--;
printf("\b \b"); // Erase the previous character from the console
}
} else {
password[i++] = ch;
printf("*"); // Print a star instead of the actual character
}

}
password[i] = '\0'; // Add null-terminator to the password string
printf("\n");
if (strcmp(password, PASSWORD) == 0) {
printf("Login Successfully!\n");
getch();
system("CLS");
return;
} else {
attempts--;
printf("Wrong password! Attempts left: %d\n", attempts);
playWrongPasswordSound();
getch();
system("CLS");
}
}
printf("Too many wrong attempts. Exiting...\n");
exit(9);
}
void addMember() {
if (numMembers >= MAX_MEMBERS) {
printf("Maximum number of members reached.\n");
return;
}
Member newMember;
printf("\n\n\t\xcd\xcd\xcd\xcd\xcd Add Member \xcd\xcd\xcd\xcd\xcd\n\n");
printf("Enter member ID: ");
scanf("%d", &newMember.id);
printf("Enter member name: ");
scanf("%s", newMember.name);
printf("Enter member age: ");
scanf("%d", &newMember.age);
members[numMembers++] = newMember;
printf("Member added successfully!\n");
getch();
system("CLS");
}
void deleteMember() {
int memberId;
int memberIndex = -1;
printf("\n\n\tEnter member ID to delete: ");
scanf("%d", &memberId);
for (int i = 0; i < numMembers; i++) {
if (members[i].id == memberId) {
memberIndex = i;
break;
}

}
if (memberIndex == -1) {
printf("Sorry...(Member is not found).\n");
getch();
system("CLS");
return;
}
for (int i = memberIndex; i < numMembers - 1; i++) {
members[i] = members[i + 1];
}
numMembers--;
printf("\n\n\tMember deleted successfully...!!\n");
printf("\n\t(Now Click any Button to Home page...)");
getch();
system("CLS");
}
void searchMember() {
int memberId;
printf("\n\n\tSearching a Member ID...\n");
printf("\t________________________\n\n");
printf("Enter member ID to search: ");
scanf("%d", &memberId);
for (int i = 0; i < numMembers; i++) {
if (members[i].id == memberId) {
printf("\nMember is found!\n");
printf("Member ID: %d\n", members[i].id);
printf("Name : %s\n", members[i].name);
printf("Age : %d\n", members[i].age);
getch();
system("CLS");
return;
}
}
printf("Sorry...!!(Member are not found).\n");
}
void addEvent() {
if (numEvents >= MAX_EVENTS) {
printf("Maximum number of events reached.\n");
return;
}
Event newEvent;
printf("\n\n\t\xcd\xcd\xcd\xcd\xcd Add Event \xcd\xcd\xcd\xcd\xcd\n\n");
printf("Enter event ID: ");
scanf("%d", &newEvent.id);
printf("Enter event name: ");
scanf("%s", newEvent.name);
printf("Enter event date: ");
scanf("%s", newEvent.date);

events[numEvents++] = newEvent;
printf("Event added successfully...!!\n");
printf("\n\t(Now Click any Button to Home page...)");
getch();
system("CLS");
}
void deleteEvent() {
int eventId;
int eventIndex = -1;
printf("\n\n\tEnter event ID to delete: ");
scanf("%d", &eventId);
for (int i = 0; i < numEvents; i++) {
if (events[i].id == eventId) {
eventIndex = i;
break;
}
}
if (eventIndex == -1) {
printf("\n\t(Event not found). Please try again...\n");
getch();
system("CLS");
return;
}
for (int i = eventIndex; i < numEvents - 1; i++) {
events[i] = events[i + 1];
}
numEvents--;
printf("\n\tEvent deleted successfully...!!\n");
printf("\n\t(Now Click any Button to Home page...)");
getch();
system("CLS");
}
void editMemberInfo() {
int memberId;
int memberIndex = -1;
printf("\n\n\t=============== Edit Member Information ===============\n\n");
printf("Enter member ID to Edit: ");
scanf("%d", &memberId);
for (int i = 0; i < numMembers; i++) {
if (members[i].id == memberId) {
memberIndex = i;
break;
}
}
if (memberIndex == -1) {
printf("\n(Member not found) try again...\n\n");
getch();
system("CLS");

return;
}
printf("Enter new member name: ");
scanf("%s", members[memberIndex].name);
printf("Enter new member age: ");
scanf("%d", &members[memberIndex].age);
printf("Member information updated successfully...!\n");
getch();
system("CLS");
}
void displayMembers() {
if (numMembers == 0) {
printf("\n\n\tSorry...!! (no members to display).\n");
printf("\n\t(Now Click any Button to Home page...)");
getch();
system("CLS");
return;
}
// Sort members by ID
for (int i = 0; i < numMembers - 1; i++) {
for (int j = 0; j < numMembers - i - 1; j++) {
if (members[j].id > members[j + 1].id) {
Member temp = members[j];
members[j] = members[j + 1];
members[j + 1] = temp;
}
}
}
printf("\n\n\t\t\xcd\xcd\xcd\xcd\xcd Member Details \xcd\xcd\xcd\xcd\xcd\n\n");
printf("\nMember ID\tMember Name\t\tMember Age\n");
printf("________________________________________________________\n");
for (int i = 0; i < numMembers; i++) {
printf("%-10d\t%-20s\t%d\n", members[i].id, members[i].name, members[i].age);
}
printf("\n");
getch();
system("CLS");
}
void displayEvents() {
if (numEvents == 0) {
printf("Sorry...!! (no events to display).\n");
return;
}
printf("\n\n\t\t\xcd\xcd\xcd\xcd\xcd Event Details \xcd\xcd\xcd\xcd\xcd\n\n");
printf("\tEvent ID\tEvent Name\t\tEvent Date\n");
printf("\t________________________________________________________\n");
for (int i = 0; i < numEvents; i++) {
printf("\t%-10d\t%-20s\t%s\n", events[i].id, events[i].name, events[i].date);

}
printf("\n");
getch();
system("CLS");
}
void mainMenu() {
int choice;
while (1) {
printf("\t\t\t\t\t\xcd\xcd\xcd\xcd\xcd IT Club Management System\xcd\xcd\xcd\xcd\xcd");
printf("\n\n\t\t\t\t\t=====================================\n");
printf("\t\t\t\t\t\t1. Add Member\n");
printf("\t\t\t\t\t\t2. Delete Member\n");
printf("\t\t\t\t\t\t3. Search Member\n");
printf("\t\t\t\t\t\t4. Add Event\n");
printf("\t\t\t\t\t\t5. Delete Event\n");
printf("\t\t\t\t\t\t6. Edit Member Information\n");
printf("\t\t\t\t\t\t7. Display Members (Sort by ID)\n");
printf("\t\t\t\t\t\t8. Display Events\n");
printf("\t\t\t\t\t\t9. Exit\n\n");
printf("\t\t\t\t\t=====================================\n");
printf("\t\t\t\t\tChoose an option: ");
scanf("%d", &choice);
getch();
system("CLS");
switch (choice) {
case 1:
addMember();
break;
case 2:
deleteMember();
break;
case 3:
searchMember();
break;
case 4:
addEvent();
break;
case 5:
deleteEvent();
break;
case 6:
editMemberInfo();
break;
case 7:
displayMembers();
break;
case 8:
displayEvents();
break;
case 9:
printf("Exiting...\n");
exit(9);

default:
printf("Sorry Invalid choice. Please try again...\n");
getch();
system("CLS");
}
}
}
int main() {
login();
mainMenu();
return 0;
}
