#include <stdio.h>


/* Correct solution 1 */
int main() {
    char username[25];
    char resultant[25] = "";
    int i,j,flag=0, count=0, index=0;

    printf("Enter username: ");
    scanf("%s",username);

    for(i=0; username[i] != '\0'; i++){

        j=0;
        flag=1;
        while(resultant[j] != '\0'){
            if(username[i] == resultant[j]) {
                flag=0;
            }
            j++;
        }

        if(flag == 1) {
            resultant[index] = username[i];
            index++;
            count++;
        }
    }

    if(count%2 == 1) printf("IGNORE HIM!");
    else printf("CHAT WITH HER!");
    return 0;

}



/* Correct solution 2 */
int main() {
    char array[55] = "sevenkplus";
    int alphabets[55];
    int i,j, nums_odd=0;

    for(i=0; i<26; i++){
        alphabets[i] = 0;
    }

    for(i=0; array[i] != '\0'; i++){
        ++alphabets[array[i] - 'a'];
        if(alphabets[array[i] - 'a'] == 1){
           
            nums_odd++;
        }
    }


    if(nums_odd%2 == 1) printf("IGNORE HIM!");
    else printf("CHAT WITH HER!");
    return 0;
}




/* Wrong attempt */
/*int main() {
    char array[25] = "xiaodao";
    int *help = (int*)calloc(25,sizeof(int));
    int count=0, index=0, length=0;

    while(array[index] != '\0'){
        ++help[index];
        index++;
    }

    while(count != index){
        if(help[count] >= 2) {
            printf("IGNORE HIM!");
            return 0;
        }
        count++;

    }
    
    printf("CHAT WITH HER!");
    return 0;

    
}*/