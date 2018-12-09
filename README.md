# bs-priority-queue

BuckleScript/ReasonML bindings for [tinyqueue](https://github.com/mourner/tinyqueue), a priority queue/heap implementation.

## Installation

    npm install --save bs-priority-queue

Then, add the dependency in your `bsconfig.json`:

```json
{
  "bs-dependencies": ["bs-priority-queue"]
}
```

## Usage

```reason
/* Create an empty priority queue */
let minQueue = PriorityQueue.make(Pervasives.compare);

/* Add some items */
minQueue->PriorityQueue.push(7);
minQueue->PriorityQueue.push(5);
minQueue->PriorityQueue.push(10);

/* Remove the top item */
Js.log(minQueue->PriorityQueue.pop); /* Returns Some(5) */

/* Return the top item (without removing it) */
Js.log(minQueue->PriorityQueue.peek); /* Returns Some(7) */

/* Remove the top item, throwing Not_found if the queue is empty */
Js.log(minQueue->PriorityQueue.popExn); /* Returns 7 */

/* Return the top item, throwing Not_found if the queue is empty */
Js.log(minQueue->PriorityQueue.peekExn); /* Returns 10 */

/* Get the length of the queue */
Js.log(minQueue->PriorityQueue.length); /* Returns 1 */

/* Populate a priority queue with an existing array */
let minQueue = PriorityQueue.fromArray([|7, 5, 10|], Pervasives.compare);

/* Set the top to be the max element */
let maxQueue = PriorityQueue.make((a, b) => b - a);
```
