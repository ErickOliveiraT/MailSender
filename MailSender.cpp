#include <bits/stdc++.h>
#include <windows.h>
#include <time.h>

using namespace std;

#define send system("python mail.py")
#define exit system("exit(0)")
#define cls system("cls")
#define MAX_MSG 1000
#define MAX_DST 250
#define MAX_SUB 250
#define SetColorGreen system("color 0a")

int main(void)
{
	SetConsoleTitle("MailSender by Cripto S.a");
	SetColorGreen;
	cout << "\t MailSender by Cripto S.a\n\n";
	
	char *msg = (char *) malloc(sizeof(char) * MAX_MSG);
	char *dst = (char *) malloc(sizeof(char) * MAX_DST);
	char *sub = (char *) malloc(sizeof(char) * MAX_SUB);
	if (!msg or !dst or !sub) exit;
	
	cout << "Destinatination Address: ";
	scanf(" %[^\n]s", dst);
	cout << "Subject: ";
	scanf(" %[^\n]s", sub);
	cout << "\nMessage: ";
	scanf(" %[^\n]s", msg);
	
	FILE *exp = fopen("config.py", "w");
	if(!exp) exit;
	
    string address = ""; //Enter the source address here
    string pass = ""; //Enter the source address password here
    char chr = '"';
    
	fprintf(exp, "EMAIL_ADDRESS = %c", chr);
	int i;
	for (i = 0; i < address.length(); i++) fprintf(exp, "%c", address[i]);
	fprintf(exp, "%c\n", chr);
	fprintf(exp, "PASSWORD = %c", chr);
	for (i = 0; i < pass.length(); i++) fprintf(exp, "%c", pass[i]);
	fprintf(exp, "%c\n", chr);
	fprintf(exp, "EMAIL_DEST = %c", chr);
	for (i = 0; i < strlen(dst); i++) fprintf(exp, "%c", dst[i]);
	fprintf(exp, "%c\n", chr);
	fprintf(exp, "SUBJ = %c", chr);
	for (i = 0; i < strlen(sub); i++) fprintf(exp, "%c", sub[i]);
	fprintf(exp, "%c\n", chr);
	fprintf(exp, "MSGE = %c", chr);
	for (i = 0; i < strlen(msg); i++) fprintf(exp, "%c", msg[i]);
	fprintf(exp, "%c", chr);
	fclose(exp);
	cout << "\n\nSending...  ";
	
	send;
		
	fflush(stdin);
	cout << "\n\nNew e-mail? (y/n)  ";
	char op;
	scanf("%c", &op);
	int ascii = ("%d", op);
	if (ascii == 78) ascii = 110;
	else if (ascii == 89) ascii = 121;
	
	switch (ascii)
	{
		case 110:
			exit;
			break;
		case 121:
			cls;
			main();
		default:
			exit;
			break;
	}		
}
