use proconio::input;
use std::io;

fn read_to_int() -> u32 {
    let mut buffer: String = String::new();
    io::stdin()
        .read_line(&mut buffer)
        .expect("Failed To Read from Input");
    buffer.trim().parse::<u32>().unwrap()
}

fn read_row(length: u32) -> [u32; length] {
    let mut buffer: String = String::new();
    io::stdin()
        .read_line(&mut buffer)
        .expect("Failed to read row");
}

fn main() {
    input! {
        num_tests: u16
    }

    for _t in 1..num_tests {
        let matrix_size: u32 = read_to_int();
        for _r in 1..matrix_size {}
        println!("{}", matrix_size);
    }
}
