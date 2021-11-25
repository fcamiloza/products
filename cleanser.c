#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


// Max number of items per price range
const int max_items = 4;

// Assign ranges for prices
// Low range
const float min_low = 1.99;
const float min_high = 12.99;

// Medium range
const float med_low = 13.00;
const float med_high = 25.99;

// High range
//TBD

// Struct for skin type and brand
typedef struct 
{
    char *skin;
    char *brand;
    
} product;

// Products for low price range
product price_low[]=
{
    {"Dry", "CeraVe Hydrating Facial Cleanser, $3.99"},
    {"Combination", "innisfree Hydrating Cleansing Foam with Green Tea, $10.00"},
    {"Oily", "Cetaphil Pro Oil Removing Foam Wash, $9.79"},
    {"Normal", "First Aid Beauty Pure Skin Face Cleanser, $11.00"}
};

// Products for medium price range
product price_med[]=
{
    {"Dry", "LANEIGE Moisturizing Cream Cleanser, $23.00"},
    {"Combination", "Kiehl's Ultra Facial Cleanser, $22.00"},
    {"Oily", "Origins Checks and Balances Frothy Face Wash, $25.00"},
    {"Normal", "Clinique Foaming Sonic Facial Soap, $22.50"}
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

        printf("What is your budget in USD? i.e. 2.00\n");
        scanf("%s", str);
        user.price = atof(str);
        printf("Budget: %.02f\n", user.price);

        // Ensure user enters a value of at least 1
        if (user.price < 2.0)
        {
            printf("Enter a value equal to or greater than $2.00");
        }


    } 

    while(user.price < 2.0);
    
    // Print out product for min price range
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

    // Print out product for med price range
    if ( user.price >= med_low && user.price <= med_high)
    {
        for( int i = 0; i < max_items; i++)
        {
            if (strcmp(user.skin_type, price_med[i].skin) == 0)
            {
                printf("%s\n", price_med[i].brand);
            }
        }
    }
}
