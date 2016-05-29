// Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
// If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
// For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
// Evaluate the sum of all the amicable numbers under 10000.

fn d(n: u32) -> u32 {
    let mut count = 0;
    for i in 1..n {
        if n%i == 0 {
            count += i;
        }
    }
    return count;
}

fn main() {
    // println!("d(220): {}", d(220));
    let mut sum = 0;
    for a in 1..10000 {
        let b = d(a);
        if a == b {
            continue;
        }
        if d(b) == a {
            sum += a;
        }
    }
    println!("sum: {}", sum);
}
