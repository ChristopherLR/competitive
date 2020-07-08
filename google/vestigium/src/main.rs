use std::collections::HashSet;
use std::io;
use std::str::FromStr;

fn read_int() -> u32 {
    let mut buffer: String = String::new();
    io::stdin()
        .read_line(&mut buffer)
        .expect("Failed To Read from Input");
    buffer.trim().parse::<u32>().unwrap()
}

fn read_matrix(size: u32) -> Vec<Vec<u32>> {
    let mut mtx = Vec::new();
    for _r in 0..size {
        let mut buf: String = String::new();
        let mut mtx_row = Vec::new();
        io::stdin()
            .read_line(&mut buf)
            .expect("Could no read matrix");
        let mtx_buf: Vec<&str> = buf.trim().split(" ").collect();
        for s in mtx_buf {
            mtx_row.push(u32::from_str(s).unwrap());
        }
        mtx.push(mtx_row);
    }
    mtx
}

fn column_dup(col: u32, size: u32, matrix: &Vec<Vec<u32>>) -> (u32, u32) {
    let mut col_vals = HashSet::new();
    let mut row_vals = HashSet::new();
    let (mut c_d, mut r_d) = (1, 1);
    for c in 0..size {
        col_vals.insert(matrix[col as usize][c as usize]);
        row_vals.insert(matrix[c as usize][col as usize]);
    }
    if col_vals.len() == size as usize {
        c_d = 0;
    }
    if row_vals.len() == size as usize {
        r_d = 0;
    }
    (c_d, r_d)
}

pub fn trace(size: u32, matrix: &Vec<Vec<u32>>) -> (u32, u32, u32) {
    let (mut tr, mut c_d, mut r_d) = (0, 0, 0);
    for t in 0..size {
        tr += matrix[t as usize][t as usize];
        match column_dup(t, size, matrix) {
            (r, c) => {
                r_d += r;
                c_d += c;
            }
        }
    }
    (tr, r_d, c_d)
}

fn main() {
    let num_tests: u32 = read_int();
    for t in 0..num_tests {
        let matrix_size: u32 = read_int();
        let matrix: Vec<Vec<u32>> = read_matrix(matrix_size);
        match trace(matrix_size, &matrix) {
            (trace, r_d, c_d) => println!("Case #{}: {} {} {}", t + 1, trace, r_d, c_d),
        }
    }
}
