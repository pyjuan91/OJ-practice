use proconio::input;

fn main() {
    input! {
        rating: i32,
        division: i32,
    }
    let valid_range = match division {
        1 => 1600..3000,
        _ => 1200..2400,
    };
    let result = if valid_range.contains(&rating) {
        "Yes"
    } else {
        "No"
    };
    println!("{}", result);
}
