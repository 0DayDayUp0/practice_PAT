/**
 * 题目如输出
 */

var t = [
    ['A', 'B', 'C'],
    ['a', 'b'],
    ['1', '2', '3']
]

var public_list = [];
function f(head_string, index)
{
    if(t[index])
        t[index].forEach(e => {
            f(head_string + e, index + 1)
        })
    else
        public_list.push(head_string);
}
f("", 0)
console.log(public_list);


var q = [""];
for(const i = 0; i < t.length; i++)
    while(q[0].length == i)
    {
        const head = q.shift();
        t[i].forEach(e => {
            q.push(head + e)
        })
    }
console.log(q);
