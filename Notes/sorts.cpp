//bubble sort(outer loop: i=0 -> j< n-1, inner loop = j=0 -> j< n-i-1, if(arr[j]>arr[j+1]) then swap

/*selectionSort(outer loop: i=1 -> i<n-1, inner loop = j=0 -> j<n, min_idx = i before inner loop, 
inside inner loop if(arr[min_idx] > arr[j]) then min_idx = j.
after inner loop swap arr[i] and arr[min_idx] */

/*insertion sort(outer loop goes: i = 1 -> i<n, key = arr[i], j = i-1 before inner loop)
  inner while loop(arr[j]>key && j>=0), inside loop = arr[j+1] = arr[j] (shifting elements to the right), j--, 
  once outside inner loop arr[j+1] = key
*/
