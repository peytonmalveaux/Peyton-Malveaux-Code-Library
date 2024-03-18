#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char course_Name[80];
    char course_Sched[4];
    unsigned course_Hours;
    unsigned course_Size;
    unsigned padding;
} COURSE;

void flush() //Used to flush input buffer
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main(int argc, char *argv[]) {
    FILE *file;
    COURSE course;
    int coursenumber;
    char coursename[80];
    char buf[200];

    long int recordsize;

    // check for courses.dat
    file = fopen("courses.dat", "rb+");
    if (file == NULL) {
        file = fopen("courses.dat", "rb+");
        if (file == NULL) {
            printf("Error creating the file.\n");
            return 1; // Exit
        }
    }
    recordsize = sizeof(COURSE);

    // loop for menu
    while (1) {
        printf("Enter one of the following actions or press CTRL-D to exit.\n");
        printf("C - create a new course record \n");
        printf("R - read an existing course record\n");
        printf("U - update an existing course record\n");
        printf("D - delete records\n");

        if (fgets(buf, sizeof(buf), stdin) == NULL) {
            printf("CTRL-D detected or end of file reached. Exiting.\n");
            break;
        }

        switch (buf[0]) {
            case 'C':
            case 'c':
                fseek(file, 0, SEEK_END);
                fflush(stdin);

                //printf("enter course number: ");
                fscanf(stdin, "%d", &coursenumber);
                fgetc(stdin); // Consume the newline character

                //printf("Enter course name: ");
                fgets(course.course_Name, sizeof(course.course_Name), stdin);
                course.course_Name[strcspn(course.course_Name, "\n")] = '\0'; // Remove newline

                //printf("Enter course schedule: ");
                fgets(course.course_Sched, sizeof(course.course_Sched), stdin);
                course.course_Sched[strcspn(course.course_Sched, "\n")] = '\0'; // Remove newline

                //printf("enter course hours: ");
                fscanf(stdin, "%u", &course.course_Hours);
                fgetc(stdin);

                //printf("enter enrollment count: ");
                fscanf(stdin, "%u", &course.course_Size);
                fgetc(stdin);

                int found = 0;
                rewind(file);

                while (fread(&course, sizeof(COURSE), 1, file) == 1) {
                    if (course.course_Hours > 0) {
                        printf("ERROR: Course already exists\n");
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    fseek(file, 0, SEEK_END);
                    fwrite(&course, sizeof(COURSE), 1, file);
                    printf("Course added\n");
                }

                break;

            case 'U':
            case 'u':
                //printf("Enter course number to update: ");
                fscanf(stdin, "%d", &coursenumber);
                fgetc(stdin);

                int foundCourse = 0;
                long int i = (coursenumber - 1) * sizeof(COURSE);
                rewind(file);

                while (fread(&course, sizeof(COURSE), 1, file) == 1) {
                    if (course.course_Hours != 0) {
                        foundCourse = 1;
                        break;
                    }
                }

                if (foundCourse) {
                    // Update the course details
                    //printf("Enter updated course name: ");
                    fgets(course.course_Name, sizeof(course.course_Name), stdin);
                    course.course_Name[strcspn(course.course_Name, "\n")] = '\0'; // Remove newline

                    //printf("Enter updated course schedule: ");
                    fgets(course.course_Sched, sizeof(course.course_Sched), stdin);
                    course.course_Sched[strcspn(course.course_Sched, "\n")] = '\0'; // Remove newline

                    //printf("Enter updated course hours (0 to keep original): ");
                    fscanf(stdin, "%u", &course.course_Hours);

                   // printf("Enter updated enrollment count (0 to keep original): ");
                    fscanf(stdin, "%u", &course.course_Size);

                    // Seek to the position of the course in the file and update it
                    fseek(file, i, SEEK_SET);
                    fwrite(&course, sizeof(COURSE), 1, file);

                    printf("Course updated successfully.\n");
                } else {
                    printf("ERROR: Course not found.\n");
                }

                break;

            case 'R':
            case 'r':
                //printf("enter course number: ");
                fscanf(stdin, "%d", &coursenumber);
                fgetc(stdin);

                int search = 0;
                rewind(file);
                fseek(file, (coursenumber - 1) * sizeof(COURSE), SEEK_SET);

                if (fread(&course, sizeof(COURSE), 1, file) == 1) {
                    // Print the course information
                    printf("Course number: %d\n", coursenumber);
                    printf("Course name: %s\n", course.course_Name);
                    printf("Scheduled days: %s\n", course.course_Sched);
                    printf("Credit hours: %u\n", course.course_Hours);
                    printf("Enrolled Students: %u\n", course.course_Size);
                } else {
                    printf("ERROR: Course not found.\n");
                }
                break;

            case 'D':
            case 'd':
                printf("Enter course number to delete: ");
                fscanf(stdin, "%d", &coursenumber);
                fgetc(stdin);

                long int deletePosition = (coursenumber - 1) * sizeof(COURSE);
                fseek(file, deletePosition, SEEK_SET);

                if (fread(&course, sizeof(COURSE), 1, file) == 1) {
                    if (course.course_Hours != 0) {
                        // Print the course information before deleting
                        printf("Course number: %d\n", coursenumber);
                        printf("Course name: %s\n", course.course_Name);
                        printf("Scheduled days: %s\n", course.course_Sched);
                        printf("Credit hours: %u\n", course.course_Hours);
                        printf("Enrolled Students: %u\n", course.course_Size);

                        // Delete the course record
                        fseek(file, deletePosition, SEEK_SET);
                        size_t = i;
                        for (i = 0; i < sizeof(COURSE); ++i) {
                            fputc(0, file);
                        }

                        
                    printf("Course was deleted.\n");
                }
                else
                {
                    printf("ERROR: Course not found.\n");
                }
            }
            else
            {
                printf("ERROR: Course not found.\n");
            }

            fflush(stdin);
            break;
        default:
            printf("ERROR: invalid option\n");


        }   //switch
        if (feof(stdin))
        {
            printf("CTRL-D detected or end of file reached. Exiting.\n");
            break;
        }

    }  //while

    fclose(file); // Close the file before exiting

    return 0;

}
