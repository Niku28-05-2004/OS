// LOOK disk scheduling algorithm

#include <stdio.h>
#include <stdlib.h>
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            } } } }
void look(int tracks[], int n, int start, int direction) {
    int totalHeadMovement = 0;
    int currentTrack = start;
    int currentIndex = 0;
    sort(tracks, n);
    printf("Sequence of tracks visited: %d", currentTrack);
    if (direction == 1) { 
        for (int i = 0; i < n; i++) {
            if (tracks[i] >= start) {
                currentIndex = i;
                break;
            } }
        for (int i = currentIndex; i < n; i++) {
            totalHeadMovement += abs(tracks[i] - currentTrack);
            currentTrack = tracks[i];
            printf(" -> %d", currentTrack); }
        for (int i = currentIndex - 1; i >= 0; i--) {
            totalHeadMovement += abs(tracks[i] - currentTrack);
            currentTrack = tracks[i];
            printf(" -> %d", currentTrack);} }
            else { 
        for (int i = n - 1; i >= 0; i--) {
            if (tracks[i] <= start) {
                currentIndex = i;
                break;} }
        for (int i = currentIndex; i >= 0; i--) {
            totalHeadMovement += abs(tracks[i] - currentTrack);
            currentTrack = tracks[i];
            printf(" -> %d", currentTrack); }
        for (int i = currentIndex + 1; i < n; i++) {
            totalHeadMovement += abs(tracks[i] - currentTrack);
            currentTrack = tracks[i];
            printf(" -> %d", currentTrack); }
    }
    printf("\nTotal head movement: %d\n", totalHeadMovement); }
int main() {
    int n;
    printf("Enter the number of tracks: ");
    scanf("%d", &n);
    int *tracks = (int *)malloc(n * sizeof(int));
    printf("Enter the track positions: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tracks[i]); }
    int start;
    printf("Enter the starting track: ");
    scanf("%d", &start);
    int direction;
    printf("Enter the direction (1 for higher tracks, 0 for lower tracks): ");
    scanf("%d", &direction);
    look(tracks, n, start, direction);
    free(tracks);
    return 0; }



    //8
// 176,79,34,60,92,11,41,114
//head=50