type action = | AddBook(string) | Increment | ChangeInput(string);
type state = {
  book: string,
  other: string,
  numebrOfBooks: int,
  nameOfBook: string,
};

let component = ReasonReact.reducerComponent("Page");
let handleAddClick = (_event) => Js.log("clicked! yo");

let make = (~message, _children) => {
  ...component,
  reducer: (action, state) => 
    switch(action) {
    | AddBook(name) => ReasonReact.Update({...state, book: name})
    | Increment => ReasonReact.Update({...state, numebrOfBooks: state.numebrOfBooks + 1})
    | ChangeInput(name) => ReasonReact.Update({...state, nameOfBook: name})
    },
  initialState: () => {
    book: "nothing yet",
    numebrOfBooks: 0,
    other: "something else",
    nameOfBook: "",
  },
  render: ({state, send})  =>
    <div>
      <h1>(ReasonReact.string(message))</h1>
      <p>(ReasonReact.string("Book:" ++ state.book))</p>
      <p>(ReasonReact.string("Number Of Books:" ++ string_of_int(state.numebrOfBooks)))</p>
      <p>(ReasonReact.string("Name of book:" ++ state.nameOfBook))</p>
      <button onClick=((_event) => send(AddBook("TESTING!")))>
        (ReasonReact.string("SEND"))
      </button>
      <button onClick=((_event) => send(Increment))>(ReasonReact.string("ANOTHER LOGGER"))</button>
      <input value=state.nameOfBook onChange=((e) => send(ChangeInput(Obj.magic(e)##target##value))) />
    </div>, 
};
