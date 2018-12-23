type t('a);
let fromArray: (Js.Array.t('a), ('a, 'a) => int) => t('a);
let make: (('a, 'a) => int) => t('a);
[@bs.send] external push: (t('a), 'a) => unit = "push";
let peek: t('a) => option('a);
let peekExn: t('a) => 'a;
let pop: t('a) => option('a);
let popExn: t('a) => 'a;
[@bs.get] external size: t('a) => int = "length";