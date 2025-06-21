#ifndef CONFIG_H_
#define CONFIG_H_

#define CSV_FILE "data.csv" // the file that stores the data for contacts (if you change this data will not be read from the other .csv files (migrate data over) CSV means comma seperated values)
#define MAXIMUM_CHARACTERS_NAME 50 // i choose this because i dont know any people whose first + last name is longer than 50 characters, literally 50 just felt right.
#define MAXIMUM_CHARACTERS_PHONE 25 // i choose this number because the ITU-T E.164 says the maximum character count for a phone number is 15 (not including formatting) and the extra 10 is for formatting since formatting takes up more than 1 space
#define MAXIMUM_CHARACTERS_EMAIL 255 // i choose this number because the RFC 5322 doesn't allow email addresses to be over 254 characters (including the @) and the extra is for the null character at the end

// Decreasing any of the numbers above should hypothetically give more performance, but the performance increase will be unnoticeable unless you are
// specifically benchmarking. (Errors may occur if you make the numbers too high)

//  If you were to change any of the MAXIMUM characters i would change name since 50 might be a bit too high

#endif // CONFIG_H_
