# language: en
# Project CppBdd101
# file MovieDataFetcher.feature
#

Feature: ATM Money Withdrawal

    # Background:
        # Given The credit card is enabled
         # And The available balance in my account is positive
         # And the ATM has enough money

    Scenario: As an existing and enabled ATM user, I want to make a withdrawal to get money.
        Given I authenticated with a card enabled
          And The available balance in my account is positive
         When I select the option to withdraw money
          And I enter the amount of money that is less than the amount I have available and the ATM s available balance
         Then I get the money
          And The money I get is subtracted from the available balance of my account
          And The system returns the card automatically
          And The system displays the transaction completed message

    Scenario: With Concrete Data
        Given I authenticated with a card enabled
          And The available balance in my account is $10,000
          And The cashier has $100,000 in cash
         When I select the option to extract money
          And I indicate that I want to extract $1,000
         Then I get $1,000 in the form of two $500 bills
          And The balance of my account becomes $9,000
          And the cashier keeps $99,000 in cash
          And The system returns the card automatically
          And The system displays the completed transaction message
          
    # Scenario outline: Withdraw money with different card keys
        # Given The credit card is enabled
          # And The available balance in my account is positive
          # And the ATM has enough money
         # When I put the card in the ATM
          # And Enter the <pin> of the card    
    
        # Examples:

        # | pin  |
        # | 1234 |
        # | 9876 |

    # Scenario outline: …
        # Given …
         # When …
         # Then I get money
          # And the Confirmation message is displayed with the text:
# """
# Dear Customer:
# The following amount has been withdrawn from your account # <account>: <amount>.
# Thank you for using our services.
# """

        # Examples:

        # | pin  | account   | amount |
        # | 1234 | 112235489 | 5000   |
        # | 9876 | 668972214 | 6000   |

    # Scenario: Withdraw money with different card keys.
        # Given The credit card is enabled
          # And The available balance in my account is positive
          # And the ATM has enough money
         # When I put the card in the cashier
          # And I enter the following <pin> and get the result <result>:

            # | pin | result |
            # | 1234 | Error |
            # | 9876 | OK |