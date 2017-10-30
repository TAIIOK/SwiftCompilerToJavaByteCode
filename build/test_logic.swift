let logical = false
if !logical {
 print("It works")
}

let door = true
let key = false
if door && key {
 print("Welcome!")
} else {
 print("Find key")
}

let hasKey = false
let hasPassword = true
if hasKey || hasPassword {
 print("Hello!")
} else {
 print("Goodbye")
}

if door && key || hasKey || hasPassword {
 print("Go here!")
} else {
 print("Nope")
}

if (door && key) || hasKey || hasPassword {
 print("Wow!")
} else {
 print("Stop")
}
