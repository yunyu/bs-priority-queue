type t('a);

[@bs.new] [@bs.module]
external createQueue: (array('a), ('a, 'a) => int) => t('a) = "tinyqueue";

let fromArray = (data, cmp) => createQueue(data->Js.Array.copy, cmp);
let make = cmp => createQueue([||], cmp);

[@bs.send] external pushItem: (t('a), 'a) => unit = "push";
let push = (queue, item) => queue->pushItem(item);

[@bs.send] external peekTop: t('a) => Js.Nullable.t('a) = "peek";
let peek = queue => queue->peekTop->Js.Nullable.toOption;
let peekExn = queue =>
  switch (queue->peek) {
  | Some(top) => top
  | None => raise(Not_found)
  };

[@bs.send] external popTop: t('a) => Js.Nullable.t('a) = "pop";
let pop = queue => queue->popTop->Js.Nullable.toOption;
let popExn = queue =>
  switch (queue->pop) {
  | Some(top) => top
  | None => raise(Not_found)
  };

[@bs.get] external getLength: t('a) => int = "length";
let length = queue => queue->getLength;