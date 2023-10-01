const express = require('express')
const app = express();
const jwt = require('jsonwebtoken');
const PORT = 4000;

app.use(express.json());

const users = [
    {
        id: '1',
        username: 'john',
        password: 'JOHN',
        isAdmin: true,
    },
    {
        id: '2',
        username: 'jane',
        password: 'JANE',
        isAdmin: false,
    }
]

const generateAccessToken=(user)=>{
    const accessToken = jwt.sign({ id: user.id, isAdmin: user.isAdmin }, "mysecretkey",{expiresIn:"60s"});
        return accessToken;
}
const generateRefreshToken=(user)=>{
    const refreshToken = jwt.sign({ id: user.id, isAdmin: user.isAdmin }, "myRefreshsecretkey");
    return refreshToken;
}

app.post("/api/login", (req, res) => {

    const { username, password } = req.body;
    const user = users.find(u => {
        return u.username === username && u.password === password;
    });
    if (user) {
        //Generate an access token:
        const accessToken=generateAccessToken(user);
        const refreshToken=generateRefreshToken(user);
        refreshTokenArray.push(refreshToken);
        res.json({
            username:user.username,
            isAdmin:user.isAdmin,
            accessToken,
            refreshToken,
        })
    }
    else {
        res.status(400).json("Username or password is incorrect");
    }
    res.json("IT WORKS");
});



let refreshTokenArray=[];

app.post('/api/refresh',(req,res)=>{
    const refreshToken=req.body.token;
    if(!refreshToken)
    {
        return res.status(401).json("You are not authenticted");
    }
    if(!refreshTokenArray.includes(refreshToken)){
        return res.status(403).json("Refresh TOken is not valid");
    }
    jwt.verify(refreshToken,"myRefreshsecretkey",(err,user)=>{
        err & console.log(err);
        refreshTokenArray=refreshTokenArray.filter((token)=>token!==refreshToken);

        const newAccessToken=generateAccessToken(user);
        const newRefreshToken=generateRefreshToken(user);
        refreshTokenArray.push(refreshToken);
        res.status(200).json(
            {
                accessToken:newAccessToken,
                refreshToken:newRefreshToken,
            }
        );
    })
})

const verify = (req, res, next) => {
    const authheader = req.headers.authorization;
    if (authheader) {
        const token = authheader.split(" ")[1];

        jwt.verify(token, "mysecretkey", (err, user) => {
            if (err) {
                return res.status(403).json("Token is not valid!");
            }
            req.user = user;
            req.user = user;
            next();
        })
    }
    else {
        req.status(401).json("You are not authorized");
    }

}

app.delete('/api/user/:userid',verify, (req, res) => {
    
    if(req.user.id=== req.params.userid||req.user.isAdmin)
    {
        res.status(200).json("User is delted");
    }
    else{
        res.status(403).json("You are not allowed to delter the user");
    }
})

app.post("/api/logout",verify,(req,res)=>{
    const refreshToken=req.body.token;
    refreshTokenArray=refreshTokenArray.filter( (token) => token !== refreshToken);
    res.status(200).json("Ypu logged out successfully ");
});

app.listen(PORT, () => {
    console.log(`Server started at ${PORT}`)
})