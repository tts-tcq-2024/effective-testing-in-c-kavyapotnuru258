// #include <stdio.h>
// #include <assert.h>

// int alertFailureCount = 0;

// int networkAlertStub(float celcius) {
//     printf("ALERT: Temperature is %.1f celcius.\n", celcius);
//     // Return 200 for ok
//     // Return 500 for not-ok
//     // stub always succeeds and returns 200
//     return 200;
// }

// void alertInCelcius(float farenheit) {
//     float celcius = (farenheit - 32) * 5 / 9;
//     int returnCode = networkAlertStub(celcius);
//     if (returnCode != 200) {
//         // non-ok response is not an error! Issues happen in life!
//         // let us keep a count of failures to report
//         // However, this code doesn't count failures!
//         // Add a test below to catch this bug. Alter the stub above, if needed.
//         alertFailureCount += 0;
//     }
// }

// int main() {
//     alertInCelcius(400.5);
//     alertInCelcius(303.6);
//     printf("%d alerts failed.\n", alertFailureCount);
//     printf("All is well (maybe!)\n");
//     return 0;
// }
#include <stdio.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Simulate failure if temperature exceeds 200°C
    if (celcius > 200.0) {
        return 500;  // Simulated failure
    }
    return 200;  // Success
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // Increment failure count on failure
        alertFailureCount += 1;
    }
}

int main() {
    alertInCelcius(400.5);  // High temperature, should fail
    alertInCelcius(303.6);  // High temperature, should fail
    alertInCelcius(150.0);  // Lower temperature, should pass
    printf("%d alerts failed.\n", alertFailureCount);  // Should print 2 if the first two alerts failed
    assert(alertFailureCount == 2);  // This assertion should pass if the logic is correct
    printf("All is well (maybe!)\n");
    return 0;
}

