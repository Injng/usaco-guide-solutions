use std::io;

fn main() {
    let mut n = String::new();
    let mut m = String::new();

    io::stdin().read_line(&mut n);
    io::stdin().read_line(&mut m);

    let n: i32 = n.trim().parse().expect("");
    let m: i32 = m.trim().parse().expect("");

    let mut limit: Vec<i32> = Vec::new();
    let mut speed: Vec<i32> = Vec::new();
    let mut delta: Vec<i32> = Vec::new();
    let mut first: i32 = 0;

    for i in (0..n) {
	let mut dist = String::new();
	let mut slimit = String::new();
	io::stdin().read_line(&mut dist);
	io::stdin().read_line(&mut slimit);
	let dist: i32 = dist.trim().parse().expect("");
	let slimit: i32 = slimit.trim().parse().expect("");
	let end = first + dist;
	for j in (first..end) {
	    limit.push(slimit);
	}
	first = first + dist;
    }

    first = 0;

    for i in (0..m) {
	let mut dist = String::new();
	let mut sactual = String::new();
	io::stdin().read_line(&mut dist);
	io::stdin().read_line(&mut sactual);
	let dist: i32 = dist.trim().parse().expect("");
	let sactual: i32 = sactual.trim().parse().expect("");
	let end = first + dist;
	for j in (first..end) {
	    speed.push(sactual);
	}
	first = first + dist;
    }

    for a in (0..100) {
	delta.push(&limit[a] - &speed[a]);
    }

    let max = delta.iter().max();
    match max {
	None => println!(""),
	Some(i) => println!("{}", "i")
    }
}
    
