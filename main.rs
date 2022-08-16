use std::io;

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();


    let a: i32 = s
        .as_mut_str()
        .trim()
        .parse().unwrap();
    
    io::stdin().read_line(&mut s).unwrap();
    let mut b:i32 = s
        .as_mut_str()
        .trim()
        .parse().unwrap();

    let res = a*b;

    while b != 0 {
        println!("{}",a*(b%10));
        b /= 10;
    }

    println!("{}",res);
    
}
