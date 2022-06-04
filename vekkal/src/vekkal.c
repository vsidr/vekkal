// Программа: Векторный Калькулятор
// Автор: Сидоров Владислав
// Лицензия: GPL v3
// Применение: пользователь выбирает операцию из шести предложенных, затем вводит числа, после чего получает новое значение
// Операции: умножение(*),деление(/),сложение(+),вычитание(-),возведение в степень(^),факториал(!),работа с векторами(v)
// При работе с векторами доступно: сложение, вычитание, скалярное произведение
#include <stdlib.h> // Подключение библиотек
#include <stdio.h> // Подключение библиотек
int main(int argc,char *argv[])
{
    // Приветствие пользователя
    // Правила использования и условия
    printf("Здравствуйте!\n");
    printf("Вас приветствует программа 'Калькулятор'\n");
    printf("Программа проводит операцию над двумя выбранными Вами числами(векторами) и выводит получившееся значение на экран\n");
    printf("Возможные операции: умножение(*),деление(/),сложение(+),вычитание(-),возведение в степень(^),факториал(!),вектора(v)\n");
    printf("При неправильном вводе данных программа завершит работу\n");
    // Переменные
    double number1,number2; // 1 и 2 число
    double result; // Результат проведения операции над 1 и 2 числом
    char operation; // Операция
    char consent; // Согласие/отказ дальше работать с программой
    // Переменные для работы с векторами
    double *A,*B; // Первый вектор, второй вектор, результат проведения операции над векторами
    int size;
    char op; // Операция над векторами
    double res;
    do // Цикл если пользователь захочет продолжить работу с программой
    {
        // Для корректного вывода
    	setvbuf(stdout, NULL, _IONBF, 0);
    	setvbuf(stderr, NULL, _IONBF, 0);
        // Выбор операции
        printf("\nВыберите операцию(*, /, +, -, ^, !, v):");
        scanf(" %c",&operation);
        // Операции
        switch(operation)
        {
        // Работа с векторами
            case 'v':
            printf("Введите размер векторов: ");
            scanf("%i",&size);
            A = malloc(size*sizeof(int));
            B = malloc(size*sizeof(int));
            printf("Введите координаты первого вектора: ");
            for(int i=0;i<size;i++) scanf("%lf",&A[i]);
            printf("Введите координаты второго вектора: ");
            for(int i=0;i<size;i++) scanf("%lf",&B[i]);
            printf("Выберите операцию(+,-,*): ");
            scanf(" %c",&op);
            if (op == '+')
            {
                printf("Сложение векторов: ");
                for(int i=0;i<size;i++) printf("%lf ",A[i]+B[i]);
                printf("\n");
            }
            if (op == '-')
            {
                printf("Вычитание векторов: ");
                for(int i=0;i<size;i++) printf("%lf ",A[i]-B[i]);
                printf("\n");
            }
            if (op == '*')
            {
                printf("Скалярное произведение векторов: ");
                for(int i=0;i<size;i++) res += A[i]*B[i];
                printf("%lf",res);
                printf("\n");
            }
            else printf("Неправильно выбрана операция!");
            free(A);
            free(B);
        break;
        // Факториал числа
            case '!':
            printf("\nВведите число:");
            scanf(" %lf",&number1);
            double h = 1;
            double b;
            b = number1;
            if (number1 > 0) for(h = 1; h < b; h++)
            {
                number1 = number1 * (b - h);
            }
            if (number1 == 0) printf("0! = 1");
            else if (number1 < 0) printf("Факториал отрицательного числа не вычисляется");
            else printf("\n%lf! = %lf",b,number1);
        break;
        // Сложение
            case '+':
            printf("\nВведите первое число:");
            scanf(" %lf",&number1);
            printf("\nВведите второе число:");
            scanf(" %lf",&number2);
            result = number1 + number2;
            printf("\n%lf + %lf = %lf",number1,number2,result);
        break;
        // Вычитание
            case '-':
            printf("\nВведите первое число:");
            scanf(" %lf",&number1);
            printf("\nВведите второе число:");
            scanf(" %lf",&number2);
            result = number1 - number2;
            printf("\n%lf - %lf = %lf",number1,number2,result);
        break;
        // Умножение
            case '*':
            printf("\nВведите первое число:");
            scanf(" %lf",&number1);
            printf("\nВведите второе число:");
            scanf(" %lf",&number2);
            result = number1 * number2;
            printf("\n%lf * %lf = %lf",number1,number2,result);
        break;
        // Деление
            case '/':
            printf("\nВведите первое число:");
            scanf(" %lf",&number1);
            printf("\nВведите второе число:");
            scanf(" %lf",&number2);
            result = number1 / number2;
            if (number2 == 0) printf("Делить на ноль нельзя!");
            else printf("\n%lf / %lf = %lf",number1,number2,result);
        break;
        // Возведение в степень
            case '^':
            printf("\nВведите первое число:");
            scanf(" %lf",&number1);
            printf("\nВведите второе число(положительное):");
            scanf(" %lf",&number2);
            double a = 1;
            double copy = number1;
            for(a = 1; a < number2; a++)
            {
                number1 = number1 * copy;
                result = number1;
            }
            if (number2 < 0) printf("Калькулятор считает только положительные степени!");
            else printf("\n%lf ^ %lf = %lf",copy,number2,result);
        break;
        // При ошибочном введении операции
            default:
            printf("\nВы неправильно выбрали операцию!");
        }
    // Согласие/отказ дальше работать с программой
    printf("\nХотите ли Вы продолжить работу с программой(y/n):");
    scanf(" %c",&consent);
    }while(consent == 'y'); // Условие при котором работа с программой продолжится
    // Если "n", то программа завершит работу, попращавшись с пользователем
    if(consent == 'n') printf("\nСпасибо за работу!До свидания!");
    // При ошибочном введении "consent"
    else printf("\nВы сделали ошибку во время согласия!");
    return 0;
}




