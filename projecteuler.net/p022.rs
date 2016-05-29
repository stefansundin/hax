// Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
// For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
// What is the total of all the name scores in the file?

use std::error::Error;
use std::fs::File;
use std::io::prelude::*;
use std::path::Path;

fn score(name: &str) -> u32 {
    return name.chars().map( |c| c as u32 - 64 ).fold(0, |a, b| a + b);
}

fn main() {
    // Create a path to the desired file
    let path = Path::new("p022_names.txt");
    let display = path.display();

    // Open the path in read-only mode, returns `io::Result<File>`
    let mut file = match File::open(&path) {
        Err(why) => panic!("couldn't open {}: {}", display, Error::description(&why)),
        Ok(file) => file,
    };

    // Read the file contents into a string, returns `io::Result<usize>`
    let mut s = String::new();
    file.read_to_string(&mut s);
    // match  {
    //     Err(why) => panic!("couldn't read {}: {}", display, Error::description(&why)),
    //     Ok(_) => , //print!("{} contains:\n{}", display, s),
    // }

    // println!("s: {}", &s[1..4]);
    // println!("score(A): {}", score("A"));

    let mut names = s.split(",").map( |x| &x[1..x.len()-1] ).collect::<Vec<_>>();
    names.sort();
    let mut i = 1;
    let mut sum = 0;
    for name in names.iter() {
        sum += score(name) * i;
        i += 1;
    }
    println!("sum: {}", sum);
}
