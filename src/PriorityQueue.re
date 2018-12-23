type t('a);

[@bs.new] [@bs.module]
external createQueue: (array('a), ('a, 'a) => int) => t('a) = "tinyqueue";

let fromArray = (data, cmp) => createQueue(data->Js.Array.copy, cmp);
let make = cmp => createQueue([||], cmp);

[@bs.send] external push: (t('a), 'a) => unit = "push";

[@bs.send] external peekTop: t('a) => Js.Undefined.t('a) = "peek";
let peek = queue => queue->peekTop->Js.Undefined.toOption;
let peekExn = queue => peek(queue)->Belt.Option.getExn;

[@bs.send] external popTop: t('a) => Js.Undefined.t('a) = "pop";
let pop = queue => queue->popTop->Js.Undefined.toOption;
let popExn = queue => pop(queue)->Belt.Option.getExn;

[@bs.get] external size: t('a) => int = "length";