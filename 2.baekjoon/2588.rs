use std::io;

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();

    let a: i32 = s
        .trim()
        .parse()
        .unwrap();

    s.clear();
    
    io::stdin().read_line(&mut s).unwrap();

    let mut b: i32 = s
        .trim()
        .parse()
        .unwrap(); 

    let result = a*b;

    
    while b != 0 {
        println!("{}", a * (b%10));
        b /= 10;
    }
    println!("{}", result);
}
