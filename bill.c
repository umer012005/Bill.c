#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct items {
    char item[20];
    int qty;
    float price;
};

struct orders {
    char customer[50];
    char date[50];
    int numOfItems;
    struct items itm[50];
};

void generateBillHeader(char name[50], char date[30]) {
    printf("\n\n");
    printf("\t------------------------\n");
    printf("\t MOHAMMED UMER RESTAURANT\n");
    printf("\t------------------------\n");
    printf("Date:%s", date);
    printf("\tInvoice to:%s", name);
    printf("\n");
    printf("------------------------------------------\n");
    printf("Items:");
    printf("\t\tQuantity:");
    printf("\tTotal:");
    printf("\n");
    printf("------------------------------------------\n");
}

void generateBillBody(char item[30], int quantity, float price) {
    printf("%s\t\t", item);
    printf("%d\t\t", quantity);
    printf("%.2f\t\t", price);
    printf("\n");
}

void generateBillFooter(float total) {
    float dis = 0.1 * total;
    float net_total = total - dis;
    float vat = 0.05 * net_total, grand_total = vat + net_total;
    printf("------------------------------------------\n");
    printf("Sub Total\t\t\t%.2f", total);
    printf("\nDiscount @ 10%s\t\t\t%.2f", "%", dis);
    printf("\n\t\t\t\t--------");
    printf("\nNet Total\t\t\t%.2f", net_total);
    printf("\nVat @5%s\t\t\t\t%.2f", "%", vat);
    printf("\n------------------------------------------");
    printf("\nGrand Total\t\t\t%.2f", grand_total);
    printf("\n------------------------------------------");
}

int main() {
    float total = 0;
    int opt, n;
    struct orders ord;
    printf("\t============MOHAMMED UMER. RESTAURANT============");
    // printf("\n\nPlease select your preferred operation");
    printf("\n\n1.Generate Invoice");
    printf("\n2.Exit");
    printf("\n");
    printf("\n\nEnter your preferred option(1-2):");
    scanf("%d", &opt);
    fgetc(stdin);
    switch (opt) {
        case 1:
            printf("\nPlease enter the name of the customer:\t");
            fgets(ord.customer, 50, stdin);
            ord.customer[strlen(ord.customer) - 1] = '\0';
            strcpy(ord.date, __DATE__);
            printf("\nPlease enter the number of items:\t");
            scanf("%d", &n);
            ord.numOfItems = n;
            for (int i = 0; i < n; i++) {
                fgetc(stdin);
                printf("\n\n");
                printf("Please enter the item %d:\t", i + 1);
                fgets(ord.itm[i].item, 20, stdin);
                ord.itm[i].item[strlen(ord.itm[i].item) - 1] = '\0';
                printf("Please enter the quantity:\t");
                scanf("%d", &ord.itm[i].qty);
                printf("Please enter the  price:\t");
                scanf("%f", &ord.itm[i].price);
                total += ord.itm[i].qty * ord.itm[i].price;
            }
            generateBillHeader(ord.customer, ord.date);
            for (int i = 0; i < ord.numOfItems; i++) {
                generateBillBody(ord.itm[i].item, ord.itm[i].qty, ord.itm[i].price);
            }
            generateBillFooter(total);
            break;
        case 2:
            printf("\n\t\t Bye Bye :)\n\n");
            exit(0); // Exiting the program
        default:
            printf("Invalid option selected.\n");
    }
    return 0;
}
