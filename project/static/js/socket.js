const socket = io();
const btnSend = document.querySelector(".btn-send-message");

btnSend.addEventListener("click", () => {
  let message = document.querySelector("#message-input").value;
  if (message) {
    socket.emit("new_message", message);
  }

  document.querySelector("#message-input").value = "";
});

socket.on("chat", (data) => {
  let ul = document.querySelector(".message");
  let li = document.createElement("li");
  console.log(data["user"])
  li.appendChild(document.createTextNode(data["message"]));
  ul.appendChild(li);
  ul.scrollTop = ul.scrollHeight;
});
