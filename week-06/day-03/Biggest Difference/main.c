#include <stdio.h>
#include <stdlib.h>
#include <mem.h>



typedef struct
{
    char *name;
    unsigned int n_of_students;
    float *results;
}classes_t;

typedef struct
{
    char c_name[50];
    float r_diff;
}class_n_diff_t;

typedef struct
{
    char c_name[50];
    float r_best;
}best_exam_t;



classes_t create_class()
{
    classes_t class;
    char t_name[50];
    unsigned int name_size;

    printf("The name of this class is: \n");
    name_size = scanf("%s", t_name);
    class.name = (char*)calloc(name_size+1, sizeof(char));
    strcpy(class.name, t_name);

    printf("How many students took the exam in the %s class?\n", class.name);
    scanf("%d", &class.n_of_students);

    class.results = (float*)calloc(class.n_of_students, sizeof(float));
    for (int j = 0; j < class.n_of_students; ++j) {

        printf("The exam result of student number: %d\n", j + 1);
        scanf("%f", &class.results[j]);
    }

    return class;
}

class_n_diff_t* biggest_difference(classes_t *array, unsigned int array_length, class_n_diff_t *return_value)
{
    class_n_diff_t *name_diff_array;
    name_diff_array = (class_n_diff_t*)calloc(array_length, sizeof(class_n_diff_t));

    for (int i = 0; i < array_length; ++i) {
        float min = 101;
        float max = -1;
        for (int j = 0; j < array->n_of_students; ++j) {
            if (min > array[i].results[j]) {
                min = array[i].results[j];
            }
            if (max < array[i].results[j]) {
                max = array[i].results[j];
            }
        }
        strcpy(name_diff_array[i].c_name, array[i].name);
        name_diff_array[i].r_diff = max - min;
    }

    return_value->r_diff = name_diff_array[0].r_diff;
    strcpy(return_value->c_name, name_diff_array[0].c_name);

    for (int k = 0; k < array_length-1; ++k) {
        if (name_diff_array[k].r_diff < name_diff_array[k+1].r_diff) {
            return_value->r_diff = name_diff_array[k+1].r_diff;
            strcpy(return_value->c_name, name_diff_array[k+1].c_name);
        }
    }

    return name_diff_array;
}

best_exam_t* best_exam_class(classes_t *array, unsigned int array_length, char* return_value)
{
    best_exam_t *best_exam_array;
    best_exam_array = (best_exam_t*)calloc(array_length, sizeof(class_n_diff_t));
    best_exam_t best_class;
    float best = -1;

    for (int i = 0; i < array_length; ++i) {
        for (int j = 0; j < array[i].n_of_students; ++j) {
            if (best < array[i].results[j]) {
                best = array[i].results[j];
            }
        }
        strcpy(best_exam_array[i].c_name, array[i].name);
        best_exam_array[i].r_best = best;
    }

    for (int k = 0; k < array_length-1; ++k) {
        if (best_exam_array[k].r_best < best_exam_array[k+1].r_best) {
            strcpy(best_class.c_name, best_exam_array[k+1].c_name);
        } else {
            strcpy(best_class.c_name, best_exam_array[k].c_name);
        }
    }

    for (int l = 0; l < array_length; ++l) {
        if (strcmp(array[l].name, best_class.c_name) == 0) {
             strcpy(return_value, array[l].name);
        }
    }
    return best_exam_array;
}

float average(classes_t *array, unsigned int array_length)
{
    float average = 0;
    int counter = 0;

    for (int i = 0; i < array_length; ++i) {
        for (int j = 0; j < array[i].n_of_students; ++j) {
            average += array[i].results[j];
            counter++;
        }
    }

    return average / counter;
}



int main() {

    classes_t *classes;
    unsigned int c_size = 0;

    printf("How many classes took the exam?\n");
    scanf("%d", &c_size);
    classes = (classes_t*)calloc(c_size, sizeof(classes_t));

    for (int i = 0; i < c_size; ++i) {
        classes[i] = create_class();
    }

    class_n_diff_t to_print_diff;
    class_n_diff_t *to_free_p1 = biggest_difference(classes, c_size, &to_print_diff);

    char to_print_best[50];
    best_exam_t *to_free_p2 = best_exam_class(classes, c_size, to_print_best);

    printf("Class: %s Difference: %f\n", to_print_diff.c_name, to_print_diff.r_diff);
    printf("Best: %s\n", to_print_best);
    printf("Average: %f\n", average(classes, c_size));

    for (int k = 0; k < c_size; ++k) {
        free(classes[k].name);
        free(classes[k].results);
    }
    free(classes);
    free(to_free_p1);
    free(to_free_p2);

    return 0;
}