// Merge Sort
#include <iostream>

using namespace std;

int n = 10;
int arr[1000001];
int tmp[1000001]; // merge 함수에서 리스트 2개를 합친 결과를 임시로 저장

void merge(int st, int en)
{ // mid = (st+en)/2라고 할 때 정렬된 arr[st:mid], arr[mid:en]을 Merge
  // 즉 하나의 arr의 인덱스를 구간으로 나눈 것을 2개의 다른 arr 취급하여 Merge
	int mid = (st+en)/2;
	int lidx = st; // arr[st:mid]에서 값을 보기 위해 사용하는 index
	int ridx = mid; // arr[mid:en]에서 값을 보기 위해 사용하는 index
	for(int i = st; i < en; i++){
		if(ridx == en) {          // mid:en의 원소가 tmp 정렬에 전부 소모됐다면, st:mid 쪽을 소모
            tmp[i] = arr[lidx++];
        } else if (lidx == mid) { // st:mid의 원소가 tmp 정렬에 전부 소모됐다면, mid:en쪽을 소모
            tmp[i] = arr[ridx++];
        } else if(arr[lidx] <= arr[ridx]) { // 양 arr이 전부 소모되지 않았다면 원소 크기 비교
            tmp[i] = arr[lidx++];
        } else {                            // 작은 쪽을 먼저 tmp 정렬에 소모
            tmp[i] = arr[ridx++];
        }
	}
	for(int i = st; i < en; i++)
		arr[i] = tmp[i]; // tmp에 임시저장해둔 st:mid와 mid:en을 Merge Sort한 값을 arr로 옮김
}

void merge_sort(int st, int en)
{ // arr[st:en]을 Merge Sort = 하나의 arr을 둘로 나눠 Merge Sort
	if(en == st + 1) return; // 길이 1인 경우 0-1, 1-2, ... 9-10 이면 총 10개이므로 st + 1 == en이면 길이 1.
	int mid = (st+en)/2; // arr을 2개로 분리 후
	merge_sort(st, mid); // arr[st:mid]을 정렬
	merge_sort(mid, en); // arr[mid:en]을 정렬
	merge(st, en); // arr[st:mid]와 arr[mid:en]을 합치기
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

	merge_sort(0, n);
    
	for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}