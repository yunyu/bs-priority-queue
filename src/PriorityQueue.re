type t('a);

[@bs.new] [@bs.module]
external createQueue: (array('a), ('a, 'a) => int) => t('a) = "tinyqueue";

let fromArray = (data, cmp) => createQueue(data, cmp);
let make = cmp => fromArray([||], cmp);

[@bs.send] external pushItem: (t('a), 'a) => unit = "push";
let push = (queue, item) => queue->pushItem(item);

[@bs.send] external peekTop: t('a) => Js.Nullable.t('a) = "peek";
let peek = queue => queue->peekTop->Js.Nullable.toOption;

[@bs.send] external popTop: t('a) => Js.Nullable.t('a) = "pop";
let pop = queue => queue->popTop->Js.Nullable.toOption;

[@bs.get] external getLength: t('a) => int = "length";
let length = queue => queue->getLength;