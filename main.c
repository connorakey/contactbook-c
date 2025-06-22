#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h" // Includes configuration of lengths and where data is stored

// function definitions
void addContact(const char *name, const char *phone, const char *email);
void removeContact(const char *name);
int findContact(const char *name);
void viewContacts();
void deleteData();

int main() {
  int choice = 0;
  do {
    printf("\n------ Contact Book ------\n");
    printf("1. Add Contact\n");
    printf("2. Remove Contact\n");
    printf("3. Find Contact\n");
    printf("4. View Contacts\n");
    printf("5. Wipe Contacts\n");
    printf("6. Exit\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);
    while (getchar() != '\n')
      ;
    switch (choice) {
    case 1: {
      char name[MAXIMUM_CHARACTERS_NAME];
      char phone[MAXIMUM_CHARACTERS_PHONE];
      char email[MAXIMUM_CHARACTERS_EMAIL];

      printf("What is your contacts name?: ");
      fgets(name, sizeof(name), stdin);
      name[strcspn(name, "\n")] = '\0';

      printf("What is your contacts phone number: ");
      fgets(phone, sizeof(phone), stdin);
      phone[strcspn(phone, "\n")] = '\0';

      printf("What is your contacts email?: ");
      char emailtmp[sizeof(email)];
      fgets(emailtmp, sizeof(emailtmp), stdin);
      emailtmp[strcspn(emailtmp, "\n")] = '\0';

      // searches for a space if there is it breaks the case, since emails
      // cannot have spaces.
      for (int i = 0; emailtmp[i] != '\0'; i++) {
        if (emailtmp[i] == ' ') {
          printf("An email cannot contain any spaces.\n");
          break;
          break;
        }
      }

      // checks for an @ symbol if there isnt it breaks the case, since emails
      // must have an @ symbol this needs to be after the space search as it
      // copys to the actual email instead of a tmp variable
      if (strchr(emailtmp, '@') == NULL) {
        printf("Your email must include an @ symbol.\n");
        break;
      } else {
        strcpy(email, emailtmp);
      }

      addContact(name, phone, email);
      break;
    }
    case 2: {
      char name[MAXIMUM_CHARACTERS_NAME];

      printf("What is the name of the contact you wish to remove?: ");
      fgets(name, sizeof(name), stdin);
      name[strcspn(name, "\n")] = '\0';

      removeContact(name);
      break;
    }
    case 3: {
      char name[MAXIMUM_CHARACTERS_NAME];
      printf("What is the name of the contact?: ");
      fgets(name, sizeof(name), stdin);
      name[strcspn(name, "\n")] = '\0';

      if (findContact(name) == 1) {
        printf("Cannot find contact.");
        break;
      }
      break;
    }

    case 4: {
      viewContacts();
      break;
    }

    case 5: {
      char choice;
      printf("Are you sure you would like to remove all contacts? (Y/N): ");
      scanf(" %c", &choice);

      switch (choice) {
      case 'Y':
      case 'y': {
        printf("You will NOT be able to recover any data, are you sure you "
               "want to DELETE CONTACT DATA? (Y/N): ");
        scanf(" %c", &choice);

        if (choice == 'Y' || choice == 'y') {
          deleteData();
        } else {
          printf("Data will not be deleted.\n");
        }
        break;
      }
      default: {
        printf("Data will not be deleted.\n");
        break;
      }
      }
      break;
    }

    case 6: {
      printf("Goodbye! (don't worry your contacts are saved!)");
      return 0;
    }

    default: {
      printf("Your input of %d was invalid you may only use #(1-6)", choice);
      break;
    }
    }
  } while (1);

  return 0;
}

void addContact(const char *name, const char *phone, const char *email) {
  FILE *fp = fopen(CSV_FILE, "a");
  if (!fp) {
    perror("Failed to open file");
    return;
  }

  fprintf(fp, "\"%s\",\"%s\",\"%s\"\n", name, phone, email);
  fclose(fp);
}

void removeContact(const char *name) {
  FILE *fp = fopen(CSV_FILE, "r");
  FILE *tmp = fopen("temp.csv", "w");

  if (!fp || !tmp) {
    if (fp)
      fclose(fp);
    if (tmp)
      fclose(tmp);
    return;
  }

  char line[2056];
  while (fgets(line, sizeof(line), fp)) {
    char lineCopy[2056];
<<<<<<< HEAD
    strcpy(lineCopy, line);
=======
    strncpy(lineCopy, line, sizeof(lineCopy) - 1);
    lineCopy[sizeof(lineCopy) - 1] = '\0';
>>>>>>> 42c17a8 (Fixed buffer overflow possibility, formatted code.)

    char *start = lineCopy;
    char *end = NULL;

    if (*start == '"') {
      start++;
      end = strchr(start, '"');
      if (end) {
        *end = '\0';
      }
    } else {
      end = strchr(start, ',');
      if (end) {
        *end = '\0';
      }
    }

    if (strcmp(start, name) == 0) {
      continue;
    } else {
      fprintf(tmp, "%s", line);
    }
  }

  fclose(fp);
  fclose(tmp);

<<<<<<< HEAD
  if (remove(CSV_FILE) != 0) {
    perror("Failed to delete contact (failed to delete data.csv file)");
    return;
  }
=======
  remove(CSV_FILE); // needed for Windows
>>>>>>> 42c17a8 (Fixed buffer overflow possibility, formatted code.)
  if (rename("temp.csv", CSV_FILE) != 0) {
    perror("Failed to rename temp.csv to data.csv");
    return;
  }
}

int findContact(const char *name) {
  FILE *fp = fopen(CSV_FILE, "r");
  if (!fp) {
    perror("Failed to open file");
    return 0;
  }

  char line[2056];
  while (fgets(line, sizeof(line), fp)) {
    char lineCopy[2056];
<<<<<<< HEAD
    strcpy(lineCopy, line);
=======
    strncpy(lineCopy, line, sizeof(lineCopy) - 1);
    lineCopy[sizeof(lineCopy) - 1] = '\0';
>>>>>>> 42c17a8 (Fixed buffer overflow possibility, formatted code.)

    char *start = lineCopy;
    char *end = NULL;

    if (*start == '"') {
      start++;
      end = strchr(start, '"');
      if (end) {
        *end = '\0';
      }
    } else {
      end = strchr(start, ',');
      if (end) {
        *end = '\0';
      }
    }

    if (strcmp(start, name) == 0) {
      char *phoneStart = NULL;
      char *phoneEnd = NULL;
      char *emailStart = NULL;
      char *emailEnd = NULL;

      char *p = line;
      if (*p == '"') {
        p++;
        p = strchr(p, '"');
        if (!p)
          continue;
        p++;
        if (*p == ',')
          p++;
      } else {
        p = strchr(p, ',');
        if (!p)
          continue;
        p++;
      }
      phoneStart = p;

      if (*phoneStart == '"') {
        phoneStart++;
        phoneEnd = strchr(phoneStart, '"');
        if (!phoneEnd)
          continue;
        *phoneEnd = '\0';
        emailStart = phoneEnd + 2;
      } else {
        phoneEnd = strchr(phoneStart, ',');
        if (!phoneEnd)
          continue;
        *phoneEnd = '\0';
        emailStart = phoneEnd + 1;
      }

      if (*emailStart == '"') {
        emailStart++;
        emailEnd = strchr(emailStart, '"');
        if (emailEnd)
          *emailEnd = '\0';
      } else {
        emailEnd = strchr(emailStart, '\n');
        if (emailEnd)
          *emailEnd = '\0';
      }

      printf("Name: %s\n", start);
      printf("Phone Number: %s\n", phoneStart);
      printf("Email: %s\n", emailStart);

      fclose(fp);
<<<<<<< HEAD
      return 0;
=======
      return 1;
>>>>>>> 42c17a8 (Fixed buffer overflow possibility, formatted code.)
    }
  }

  fclose(fp);
<<<<<<< HEAD
  return 1;
=======
  return 0;
>>>>>>> 42c17a8 (Fixed buffer overflow possibility, formatted code.)
}

void viewContacts() {
  FILE *fp = fopen(CSV_FILE, "r");
  if (!fp) {
    perror("Failed to open file");
    return;
  }

  char line[2056];
  while (fgets(line, sizeof(line), fp)) {
    char lineCopy[2056];
<<<<<<< HEAD
    strcpy(lineCopy, line);
=======
    strncpy(lineCopy, line, sizeof(lineCopy) - 1);
    lineCopy[sizeof(lineCopy) - 1] = '\0';
>>>>>>> 42c17a8 (Fixed buffer overflow possibility, formatted code.)

    char *start = lineCopy;
    char *end = NULL;

    if (*start == '"') {
      start++;
      end = strchr(start, '"');
      if (end)
        *end = '\0';
    } else {
      end = strchr(start, ',');
      if (end)
        *end = '\0';
    }

    char *phoneStart = NULL;
    char *phoneEnd = NULL;
    char *emailStart = NULL;
    char *emailEnd = NULL;

    char *p = line;
    if (*p == '"') {
      p++;
      p = strchr(p, '"');
      if (!p)
        continue;
      p++;
      if (*p == ',')
        p++;
    } else {
      p = strchr(p, ',');
      if (!p)
        continue;
      p++;
    }
    phoneStart = p;

    if (*phoneStart == '"') {
      phoneStart++;
      phoneEnd = strchr(phoneStart, '"');
      if (!phoneEnd)
        continue;
      *phoneEnd = '\0';
      emailStart = phoneEnd + 2;
    } else {
      phoneEnd = strchr(phoneStart, ',');
      if (!phoneEnd)
        continue;
      *phoneEnd = '\0';
      emailStart = phoneEnd + 1;
    }

    if (*emailStart == '"') {
      emailStart++;
      emailEnd = strchr(emailStart, '"');
      if (emailEnd)
        *emailEnd = '\0';
    } else {
      emailEnd = strchr(emailStart, '\n');
      if (emailEnd)
        *emailEnd = '\0';
    }

    printf("Name: %s\n", start);
    printf("Phone Number: %s\n", phoneStart);
    printf("Email: %s\n\n", emailStart);
  }

  fclose(fp);
}
<<<<<<< HEAD
=======

>>>>>>> 42c17a8 (Fixed buffer overflow possibility, formatted code.)
void deleteData() {
  if (remove(CSV_FILE) == 0) {
    printf("Data deleted sucessfully.\n");
  } else {
    perror("Error deleting data");
  }
}
