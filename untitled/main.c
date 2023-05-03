#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Book{
    struct author{
        char surname[50];
        char name[50];
    }author;
    char title[100];
    int year;
}books;

void input(int num_books, books *arr);
void calculate(int num_books, int *oldest_i, int *youngest_i, int *longest_title_i, books *arr);
void output(int *oldest_i, int *youngest_i, int *longest_title_i, books *arr);
void create(int num_books, books **arr);

int main() {
    int num_books;
    printf("\tВідомості про книги - це прізвище автора, назва, рік видання. Є вектор,\nелементи якого - відомості про книги. Встановити, яка книга найстаріша\nі яка наймолодша. Знайти книгу з самою довгою назвою.\n");
    printf("\nВведіть к-сть книг: ");
    scanf("%d", &num_books);

    books *arr;

    create(num_books, &arr);

    input(num_books, arr);

    int oldest_i = 0, youngest_i = 0, longest_title_i = 0;
    calculate(num_books, &oldest_i, &youngest_i, &longest_title_i, arr);

    output(&oldest_i, &youngest_i, &longest_title_i, arr);

    free(arr);

    return 0;
}

void create(int num_books, books **arr){
    *arr = (books*)malloc(num_books*sizeof(books));
}

void input(int num_books, books *arr){
    for (int i = 0; i < num_books; i++) {
        printf("Введіть назву книжки №%d: ", i+1);
        scanf("%s", arr[i].title);
        printf("Введіть прізвище та імʼя автора книжки №%d: ", i+1);
        scanf("%s", arr[i].author.surname);
        scanf("%s", arr[i].author.name);
        printf("Введіть рік в якому була опублікована книжка №%d: ", i+1);
        scanf("%d", &arr[i].year);
    }
}

void calculate(int num_books, int *oldest_i, int *youngest_i, int *longest_title_i, books *arr){

    for (int i = 1; i < num_books; i++) {
        if (arr[i].year < arr[*oldest_i].year) {
            *oldest_i = i;
        }
        if (arr[i].year > arr[*youngest_i].year) {
            *youngest_i = i;
        }
        if (strlen(&arr[i].title) > strlen(&arr[*longest_title_i].title)) {
            *longest_title_i = i;
        }
    }
}

void output(int *oldest_i, int *youngest_i, int *longest_title_i, books *arr){

    printf("Найстаріша книжка - \"%s\", її автор - %s %s, опублікована в %d р.\n",
           arr[*oldest_i].title, arr[*oldest_i].author.surname, arr[*oldest_i].author.name, arr[*oldest_i].year);
    printf("Наймолодша книжка - \"%s\", її автор - %s %s, опублікована в %d р.\n",
           arr[*youngest_i].title, arr[*youngest_i].author.surname, arr[*youngest_i].author.name, arr[*youngest_i].year);
    printf("Книжка з найдовшою назвою - \"%s\", її автор - %s %s, опублікована в %d р.\n",
           arr[*longest_title_i].title, arr[*longest_title_i].author.surname, arr[*longest_title_i].author.name, arr[*longest_title_i].year);

}