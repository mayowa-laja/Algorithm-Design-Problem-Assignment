/*
    OS - Windows 10

    Author - Oluwamayowa Adelaja (C20376476)

    Created - 16/04/2021

    Modified - 22/04/2021 
    
    Description - Menu that displays 4 options:
                    1. Combine the 4 class lists into 1 list sorted by surname alphabetically
                    2. Search for all full-time students and display them
                    3. Search for a specific surname in the list
                    4. End the program
*/

#include <stdio.h>
#include <string.h>

#define SIZE 25
#define SIZE1 13
#define SIZE2 9
#define SIZE3 14
#define SIZE4 6
#define SIZE5 42

//structure templates
struct student_records
{
    char surname[SIZE];
    char firstname[SIZE];
    char programme[SIZE];
    char programme_type[SIZE];

};

//initialising function signatures
void merge (struct student_records*, int, struct student_records*, int, struct student_records*, int, struct student_records*, int, struct student_records*, struct student_records, int*);
void search_course_type (struct student_records*, int*);
void search_surname (struct student_records*, int*);
void end_program (int *);

int main (void)
{
    //initialising variables
    float menu1=0;
    int menu2=0;
    int end=0;
    int decision=0;
    int i=0;
    int validation=0;
    //used in character validation
    char charcheck;
    struct student_records main_array[SIZE5];
    struct student_records temp;
    

    struct student_records dt265a[SIZE1] = 
    {
        {"Rey", "Milena", "DT265A", "PART"}, {"Alo", "Tess", "DT265A", "PART"}, {"Morris", "Ealhstan", "DT265A", "PART"}, {"Meaney", "Awotwi", "DT265A", "PART"},
        {"Antonio", "Alysia", "DT265A", "PART"}, {"Reijnders", "Dorian", "DT265A", "PART"}, {"Alborz", "Metzger", "DT265A", "PART"}, {"Misra", "Teodor", "DT265A", "PART"},
        {"Bush", "Georgeta", "DT265A", "PART"}, {"Rasputin", "Boudica", "DT265A", "PART"}, {"Ware", "Sivert", "DT265A", "PART"}, {"Podsednik", "Atse", "DT265A", "PART"},
        {"Narang", "Ahti", "DT265A", "PART"}

    };

    struct student_records dt265c[SIZE2] = 
    {
        {"Aitken", "Tri", "DT265C", "PART"}, {"Simmon", "Renee", "DT265C", "PART"}, {"Harding", "Aoide", "DT265C", "PART"},
        {"Barany", "Urien", "DT265C", "PART"}, {"Novosad", "Avani", "DT265C", "PART"}, {"Sultana", "John", "DT265C", "PART"},
        {"Busto", "Edvaldo", "DT265C", "PART"}, {"Franklyn", "Liusaidh", "DT265C", "PART"}, {"Abbaticchio", "Abelone", "DT265C", "PART"}

    };

    struct student_records dt265b[SIZE3] = 
    {
        {"Dennell", "Feroze", "DT265B", "FULL"}, {"Mullane", "Adriel", "DT265B", "FULL"}, {"Pratt", "Eskil", "DT265B", "FULL"}, {"Quintana", "Jocelyne", "DT265B", "FULL"},
        {"Furst", "Sperantia", "DT265B", "FULL"}, {"Petrovic", "Milena", "DT265B", "FULL"}, {"Bandini", "Parth", "DT265B", "FULL"}, {"Sato", "Erna", "DT265B", "FULL"},
        {"Hermans", "Ragemprand", "DT265B", "FULL"}, {"Robertsen", "Tayla", "DT265B", "FULL"}, {"Krakowski", "Jowan", "DT265B", "FULL"}, {"Sacco", "Gideon", "DT265B", "FULL"},
        {"Coughlin", "Ivan", "DT265B", "FULL"}, {"Moller", "Milka", "DT265B", "FULL"}

    };

    struct student_records dt8900[SIZE4] =
    {
        {"Terzi", "Erle", "DT8900", "FULL"}, {"Thaidhg", "Jahangir", "DT8900", "FULL"}, {"Adam", "Muireadh", "DT8900", "FULL"}, {"Machado", "Naliaka", "DT8900", "FULL"},
        {"Stroman", "Madina", "DT8900", "FULL"}, {"Hagen", "Elijah", "DT8900", "FULL"}

    };

    do
    {
        //displaying the menu to the user
        printf("\nMENU:\n1. Combine the 4 lists into 1 main list\n2. Search the main list for all full-time students\n"
        "3. Search the main list for a specific student by surname\n"
        "4. Exit Program\n");
        //scanf for the user to input their menu option
        scanf("%f%c", &menu1, &charcheck);

        //vaidation for when user enters a character in the menu
        if(charcheck!='\n')
        {
            printf("\nERROR: You entered a character\n");

        }//end if

        //vaidation for when user enters a decimal in the menu
        else if (menu1!=(int)menu1)
        {
            printf("\nERROR: You entered a number with a decimal\n");
            printf("\nPress the 'Enter' key to proceed\n");

        }//end else if
        
        else
        {
            //changing the menu variable into an integer so it can be used in the switch statement
            menu2=menu1;
            
            //switch statement so the user can choose menu options
            switch(menu2)
            {
                //first menu option
                case 1:
                {
                    //calling the merge function and passing the 4 classes and their sizes, the main array and the temp variable as parameters
                    merge (dt265a, SIZE1, dt265c, SIZE2, dt265b, SIZE3, dt8900, SIZE4, main_array, temp, &validation);
                    
                    //validation for when the list hasn't been merged and sorted
                    if(validation == 1)
                    {
                        //printing out the sorted list of students
                        for(i=0; i<SIZE5; i++)
                        {
                            printf("%d.", i+1);
                            printf("%s    ", (main_array+i) -> surname);
                            fflush(stdin);
                            printf("%s    ", (main_array+i) -> firstname);
                            fflush(stdin);
                            printf("%s    ", (main_array+i) -> programme);
                            fflush(stdin);
                            printf("%s    \n",(main_array+i) -> programme_type);
                            fflush(stdin);

                        }

                    }

                    printf("\nPress the ENTER key to continue\n");

                    //validation so when the user presses option 1 a second time around, the list isn't printed again
                    validation=2;
                    break;

                }//end case 1

                //second menu option
                case 2:
                {
                    //calling the function that searches for full-time courses
                    search_course_type (main_array, &validation);
                    break;

                }//end case 2

                //third menu option
                case 3:
                {
                    //calling the function to search for a specific surname
                    search_surname (main_array, &validation);
                    break;

                }//end case 3

                //fourth menu option
                case 4:
                {
                    //calling function to end the program
                    end_program (& end);
                    break;

                }//end case 4


                //default case which acts as a form of validation
                default:
                {
                    printf("\nInvalid Option\n");
                    break;

                }//end default

            }//end switch

        }//end else

            // used to stop an infinite loop when the user enters a character
            getchar();

    }//end do
    while (end==0);


    return 0;

}//end main

//function to merge the 4 course lists and sort it by surname alphabetically
void merge (struct student_records *dt265a, int num1, struct student_records *dt265c, int num2, struct student_records *dt265b, int num3, struct student_records *dt8900, int num4, struct student_records *main_array, struct student_records temp, int* validation)
{
    //initialising variables
    int j=0;
    int i=0;

    //validation to make sure the list hasn't already been merged and sorted
    if(*(validation) == 0)
    {
        //merging DT265A into the main array
        for(i=0; i<num1; i++)
        {
            *(main_array+i) = *(dt265a+j);
            j++;

        }//end for

        //resetting the variable to 0 so it can be used as an index
        j=0;

        //merging DT265C into the main array
        for(i=num1; i<num1+num2; i++)
        {
            *(main_array+i) = *(dt265c+j);
            j++;

        }//end for

        //resetting the variable to 0 so it can be used as an index
        j=0;

        //merging DT265B into the main array
        for(i=num1+num2; i<num1+num2+num3; i++)
        {
            *(main_array+i) = *(dt265b+j);
            j++;

        }//end for

        //resetting the variable to 0 so it can be used as an index
        j=0;

        //merging DT8900 into the main array
        for(i=num1+num2+num3; i<num1+num2+num3+num4; i++)
        {
            *(main_array+i) = *(dt8900+j);
            j++;

        }//end for

        
        //Bubble Sort algorithm modified to work with strings
        for(i=0; i<SIZE5-1; i++)
        {
            for(j=0; j<SIZE5-i-1; j++)
            {
                if( strcmp((main_array+j) -> surname, (main_array+j+1) -> surname) > 0)
                {
                    temp=main_array[j];
                    main_array[j]=main_array[j+1];
                    main_array[j+1]=temp;

                }//end if

            }//end for

        }//end for

        *(validation) = 1;

    }//end if

    else
    {
        printf("\nThe lists have already been combined\n");

    }//end else
    

}//end function

//function to search for all full-time students
void search_course_type (struct student_records *array, int* validation)
{
    //initialising variables
    int i=0;

    //validation to make sure the list has been merged and printed before searching for full-time students
    if(*(validation) == 2)
    {
        //Linear Search modified to work with strings
        for(i=0; i<SIZE5; i++)
        {
            if(strcmp((array+i) -> programme_type, "FULL") == 0)
            {
                printf("%d.", i+1);
                printf("%s    ", (array+i) -> surname);
                fflush(stdin);
                printf("%s    ", (array+i) -> firstname);
                fflush(stdin);
                printf("%s    ", (array+i) -> programme);
                fflush(stdin);
                printf("%s    \n",(array+i) -> programme_type);
                fflush(stdin);

            }//end if

        }//end for

        printf("\nPress the ENTER key to continue\n");

    }//end if

    else
    {
        printf("\nYou have to combine the 4 lists first(press option1 in the menu)\n");
        printf("\nPress the ENTER key to continue\n");

    }//end else
    

}//end function

//function to search for a specific surname
void search_surname (struct student_records *array, int *validation)
{
   //initialising variables
   int first = 0;
   int last = SIZE5-1;
   int middle = (first+last)/2;
   char name[SIZE];
   int i = 0;

    //validation to make sure the list has been merged and printed before searching for full-time students
    if (*(validation) == 2)
    {
        printf("\nEnter the surname you want to search for\n");
        scanf("%s", name);

        //Binary Search modified to work with strings
        while(first <= last)
        {
            if(strncmp((array+middle) -> surname, name, strlen( name ) ) < 0)
            {
                first = middle+1;

            }//end if

            else if(strncmp(name, (array+middle) -> surname, strlen( name ) ) == 0)
            {
                printf("\nThe surname '%s' is found at number %d of the list\n", (array+middle) -> surname, middle+1);
                break;

            }//end else if

            else
            {
                last = middle - 1;
            
            }//end else

            middle = (first + last)/2;
            

        }//end while

        if(first > last)
        {
            printf("\nThe surname is not found in the list\n");

        }//end if

    }//end if

    else
    {
        printf("\nYou have to combine the 4 lists first(press option1 in the menu)\n");
        printf("\nPress the ENTER key to continue\n");

    }//end else
    

}//end function

//function to end the program
void end_program(int* end)
{
    //initialising variables
    float decision=0;
    char charcheck;

    //asking the user if they want to end the program for sure
    printf("\nAre you sure you want to end the program\n1. Yes\n2. No\n");
    scanf("%f%c", &decision, &charcheck);
    
    //if statement to check if a character was inputted and to display the appropriate error message
    if(charcheck!='\n')
    {
        printf("\nERROR: You entered a charcter\n");
        *(end)=0;

    }//end if

    //else if statement to check if a decimal was inputted and to display the appropriate error message
    else if(decision!=(int)decision)
    {
        printf("\nERROR: You entered a decimal\n");
        printf("\nPress the 'Enter' key to proceed\n");
        *(end)=0;

    }//end else if
    
    //else if statement for if the user wants to end the program
    else if(decision==1)
    {
        printf("\nYou have chosen to end the program");
        *(end)=1;

    }//end if
    
    //else if statement for if the user does not want to end the program
    else if(decision==2)
    {
        printf("\nYou chose not to end the program\n");
        *(end)=0;

    }//end else

    else 
    {
        printf("\nInvalid input\n");
        *(end)=0;

    }//end else
    

}//end function