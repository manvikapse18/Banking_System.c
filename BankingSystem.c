#include <stdio.h>

struct Bank
{
    int accountNo;
    char name[50];
    float balance;
};
void deposit(struct Bank *b);
void withdraw(struct Bank *b);
void balanceEnquiry(struct Bank b);
void saveData(struct Bank b);

int main()
{
    struct Bank b;
    int choice;
    FILE *fp;
    fp = fopen("bank.txt", "r");
    if (fp == NULL)
    {
        printf("Enter Account Number:");
        scanf("%d", &b.accountNo);
        printf("Enter Account Holder Name:");
        scanf(" %49[^\n]", b.name);
        b.balance = 0;
    }
    else
    {
        fscanf(fp, "%d\n", &b.accountNo);
        fscanf(fp, " %49[^\n]", b.name);
        fscanf(fp, "%f", &b.balance);
        fclose(fp);
        
    }
    do
    {
        printf("\n BANKING SYSTEM\n");
        printf("1.Deposit\n");
        printf("2.Withdraw\n");
        printf("3.Balance Enquiry\n");
        printf("4.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            deposit(&b);
            saveData(b);
            break;
        case 2:
            withdraw(&b);
            saveData(b);
            break;
        case 3:
            balanceEnquiry(b);
            break;
        case 4:
            saveData(b);
            printf("Thank you for using our banking system!\n");
            break;
        default:
            printf("invalid choice! Please try again.\n");
        }

    } while (choice != 4);
    return 0;
}
void deposit(struct Bank *b)
{
    float amount;
    printf("Enter amount to deposit:");
    scanf("%f", &amount);
    if (amount > 0)
    {
        b->balance = b->balance + amount;
        printf("Amount deposited successfully!\n");
    }
    else
    {
        printf("Invalid amount!\n");
    }
}
void withdraw(struct Bank *b)
{
    float amount;
    printf("Enter amount to withdraw:");
    scanf("%f", &amount);
    if (amount <= 0)
    {
        printf("Invalid amount!\n");
    }
    else if (amount <= b->balance)
    {
        b->balance = b->balance - amount;
        printf("Amount withdrawn successfully!\n");
    }
    else
    {
        printf("insufficient balance!\n");
    }
}
void balanceEnquiry(struct Bank b)
{
    printf("\nAccount Number: %d\n", b.accountNo);
    printf("Account Holder: %s\n", b.name);
    printf("Available Balance: Rs. %.2f\n", b.balance);
}
void saveData(struct Bank b)
{
    FILE *fp;
    fp = fopen("bank.txt", "w");
    if (fp == NULL)
    {
        printf("Error saving account data!\n");
        return;
    }

    fprintf(fp, "%d\n", b.accountNo);
    fprintf(fp, "%s\n", b.name);
    fprintf(fp, "%.2f\n", b.balance);
    fclose(fp);
}