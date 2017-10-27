func fact(kek:Int) -> Int {


    if(kek < 0){
        return 0
    }

    if(kek == 1){
        return 1
    }

    return kek * fact(kek:kek - 1)
    
}

var d = toInt(readLine())

var s = 1

print(d)

s = fact(kek:d)

print(s)
