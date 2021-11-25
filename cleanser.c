#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


// Max number of items per price range
const int max_items = 4;

// Assign ranges for prices
const float min_low = 1.99;
const float min_high = 9.99;

const float med_low = 10.00;
const float med_high = 24.99;

// Struct for skin type and brand
typedef struct 
{
    char *skin;
    char *brand;
    
} product;

// Products for low price range
product price_low[]=
{
    {"Dry", "Dove Moisturizing Cleanser"},
    {"Combination", "Lush Soap Bar"},
    {"Oily", "Brand Name Oily"},
    {"Normal", "Brand Name Normal"}
};

// Struct for price range
typedef struct
{
    float price;
    char skin_type[256];
} cleanser_choice;
    

int main()
{
    cleanser_choice user;
    
    // Get skin type from user
    // char skin_type[256];
    printf("What is your skin type? (Normal, Oily, Dry, Combination): ");
    scanf("%s", user.skin_type);
    printf("Skin type: %s\n", user.skin_type);
    
    
    // Get budget from user
    do
    {   
        char str[32];

        printf("What is your budget in USD? i.e. 1.00\n");
        scanf("%s", str);
        user.price = atof(str);
        printf("Budget: %.02f\n", user.price);

        // Ensure user enters a value of at least 1
        if (user.price < 1.0)
        {
            printf("Enter a value equal to or greater than 1");
        }


    } 
    while(user.price < 1.0);
    
    // Print out product for the specified price
    if ( user.price >= min_low && user.price <= min_high)
    {
        for( int i = 0; i < max_items; i++)
        {

            if (strcmp(user.skin_type, price_low[i].skin) == 0)
            {
                printf("%s\n", price_low[i].brand);
            }

        }
    }
}
