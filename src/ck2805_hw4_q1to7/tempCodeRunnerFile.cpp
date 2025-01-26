
    cout << "I thought of a number betweem 1 and 100! Try to guess it. \n "
    << "Range: ["<<a<< ", "<< b<<"], number of guess left " <<numGuesses << endl;
    cin >> guess;

    while (secretNumber != guess) {
        if (guess > secretNumber) {
            cout << "Your guess is higher than the number!" << endl;
        } else {
            cout << "Your guess is lower than the number!" << endl;
        }
        cout << "Enter another guess: ";
        cin >> guess;
    }

    // This executes when the user guesses correctly
    cout << "Congrats!! You guessed right!!" << endl;

    return 0;
}
