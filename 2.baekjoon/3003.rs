use std::io;

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();


    let list:Vec<i32> = s
        .as_mut_str()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();
    

    let _list = vec![1,1,2,2,2,8];
    
    for i in 0..6 {
        print!("{} ", _list[i] - list[i]);
    }
    
}
