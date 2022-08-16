use std::io;

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();


    let values:Vec<i32> = s
        .as_mut_str()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();


    let A = values[0];
    let B = values[1];
    let C = values[2];

    println!("{}", (A+B)%C);
    println!("{}", ((A%C) + (B%C))%C);
    println!("{}", (A*B)%C);
    println!("{}", (((A%C) * (B%C))%C ));
}
