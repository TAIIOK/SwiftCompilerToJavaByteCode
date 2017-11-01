
func ki(array:Array<Int>){

var mas1:[Int] = [5,2,3,4,1,2]



var i:Int = 0

var N = array.count()

var j = 0

var tmp = 0

while(i < N){

mas1[i] = array[i]

i = i + 1

}

i = 0

while (i < N - 1){

while(j < N - 1){

    if(mas1[j] > mas1[j + 1]){

        tmp = mas1[j]
        mas1[j] = mas1[j + 1]
        mas1[j + 1] = tmp


    }

    j = j + 1

}

j = 0

i = i + 1

}

i = 0

while(i < N){
print(mas1[i])
i = i + 1
}

}
var s:[Int] = [7,5,3,4,9,6]
ki(array:s)
