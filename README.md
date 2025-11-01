
<html lang="zh-TW">
<head>
    <meta charset="UTF-8">
    <title>雄中115的會沅制餐廳</title>
    
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.2/css/all.min.css">
    <link href="https://fonts.googleapis.com/css2?family=Noto+Sans+TC:wght@400;500;700&display=swap" rel="stylesheet">
    <style>
        body { 
            font-family: 'Noto Sans TC', Arial, sans-serif; 
            margin: 0; 
            padding: 20px; 
            background: linear-gradient(135deg, #fff6e5 0%, #fff0db 100%);
            min-height: 100vh;
        }
        .header { 
            display: flex; 
            justify-content: space-between; 
            align-items: center;
            padding: 12px 20px;
            background: white;
            border-radius: 12px;
            box-shadow: 0 2px 12px rgba(255, 87, 34, 0.1);
            margin-bottom: 24px;
        }
        h1 { 
            margin: 0; 
            background: linear-gradient(45deg, #ff5722, #ff7043);
            -webkit-background-clip: text;
            background-clip: text;
            -webkit-text-fill-color: transparent;
            font-size: 1.8rem;
            font-weight: 700;
        }
        .cart-button { 
            position: relative; 
            padding: 10px 18px;
            background: linear-gradient(45deg, #ff5722, #ff7043);
            color: #fff;
            border: none;
            border-radius: 8px;
            cursor: pointer;
            font-weight: 500;
            transition: transform 0.2s, box-shadow 0.2s;
        }
        .cart-button:hover {
            transform: translateY(-1px);
            box-shadow: 0 4px 12px rgba(255, 87, 34, 0.3);
        }
        .cart-count { 
            position: absolute;
            top: -8px;
            right: -8px;
            background: #4caf50;
            color: #fff;
            border-radius: 50%;
            padding: 3px 7px;
            font-size: 12px;
            box-shadow: 0 2px 6px rgba(255,68,68,0.4);
        }

        .categories { 
            display: grid; 
            grid-template-columns: repeat(auto-fit, minmax(240px, 1fr)); 
            gap: 20px; 
            margin-top: 24px;
            padding: 0 10px;
        }
        .category-card { 
            background: white; 
            border-radius: 16px; 
            padding: 24px; 
            text-align: center; 
            box-shadow: 0 4px 20px rgba(0,0,0,0.06); 
            cursor: pointer;
            transition: transform 0.3s, box-shadow 0.3s;
            position: relative;
            overflow: hidden;
        }
        .category-card:hover {
            transform: translateY(-2px);
            box-shadow: 0 8px 30px rgba(0,0,0,0.1);
        }
        .category-card h2 { 
            margin: 12px 0 0 0;
            color: #ff5722;
            font-weight: 600;
        }
        .category-card.active {
            background: #fff5f2;
            border: 2px solid #ff5722;
        }

        /* 商品列表 (已修改樣式以減少晃動) */
        #itemsContainer { 
            margin-top: 20px; 
            display: grid; 
            grid-template-columns: repeat(auto-fill, minmax(200px,1fr)); 
            gap: 16px;
            opacity: 0;
            transform: translateY(20px);
            transition: opacity 0.3s, transform 0.3s;
            min-height: 120px; /* 鎖定最小高度 */
            overflow: hidden; 
        }
        #itemsContainer.show {
            opacity: 1;
            transform: translateY(0);
        }
        .item-card { 
            background: white; 
            padding: 16px; 
            border-radius: 12px; 
            box-shadow: 0 4px 16px rgba(0,0,0,0.06);
            transition: transform 0.2s, box-shadow 0.2s;
        }
        .item-card:hover {
            transform: translateY(-2px);
            box-shadow: 0 6px 24px rgba(0,0,0,0.1);
        }
        .item-card h3 { 
            margin: 0 0 8px 0; 
            font-size: 17px;
            color: #e65100;
        }
        .item-card p { 
            margin: 0 0 12px 0; 
            color: #ff5722;
            font-weight: 500;
        }
        .item-card button { 
            background: linear-gradient(45deg, #ff5722, #ff7043);
            color: white;
            border: none;
            padding: 8px 16px;
            border-radius: 8px;
            cursor: pointer;
            font-weight: 500;
            transition: transform 0.2s, box-shadow 0.2s;
        }
        .item-card button:hover {
            transform: translateY(-1px);
            box-shadow: 0 4px 12px rgba(255, 87, 34, 0.3);
        }

        /* 購物車彈窗 */
        .modal { 
            display: none; 
            position: fixed; 
            inset: 0; 
            background: rgba(0,0,0,0.6); 
            align-items: center; 
            justify-content: center;
            backdrop-filter: blur(4px);
        }
        .modal.open { 
            display: flex;
            animation: modalFadeIn 0.3s ease-out;
        }
        @keyframes modalFadeIn {
            from { opacity: 0; transform: translateY(-20px); }
            to { opacity: 1; transform: translateY(0); }
        }
        .modal-content { 
            background: white; 
            width: 90%; 
            max-width: 520px; 
            border-radius: 16px; 
            padding: 24px;
            box-shadow: 0 20px 60px rgba(0,0,0,0.2);
        }
        .cart-item { 
            display: flex; 
            justify-content: space-between; 
            padding: 12px 0; 
            border-bottom: 1px solid #eee;
            align-items: center;
        }
        .cart-total { 
            text-align: right; 
            margin-top: 16px; 
            font-weight: bold;
            color: #e65100;
            font-size: 1.2em;
        }
        .close { 
            float: right; 
            cursor: pointer; 
            font-size: 24px;
            color: #666;
            transition: color 0.2s;
        }
        .close:hover {
            color: #ff5722;
        }

        /* 新的圖示聯絡區塊樣式 */
        .contact-info-icon {
            margin-top: 40px;
            text-align: center; /* 讓內容居中 */
            padding: 20px 0;
        }
        .contact-info-icon p {
            font-size: 1rem;
            color: #555;
            margin-bottom: 15px;
        }
        .ig-icon-link {
            text-decoration: none;
            color: #833AB4; /* Instagram 紫色 */
            display: inline-block;
            transition: transform 0.2s, color 0.2s;
        }
        .ig-icon-link i {
            font-size: 48px; /* 設定圖示大小 */
        }
        .ig-icon-link:hover {
            color: #C135A2; /* 懸停變色 */
            transform: scale(1.1); /* 懸停放大 */
        }
    </style>
</head>
<body>
    <div class="header">
        <h1>雄中115的會沅制餐廳</h1>
        <button class="cart-button" onclick="openCart()">購物車 <span class="cart-count">0</span></button>
    </div>

    <div class="categories" aria-label="主要分類">
        <div class="category-card" onclick="showCategoryItems('主食')"><div style="font-size:36px">🍜</div><h2>主食</h2></div>
        <div class="category-card" onclick="showCategoryItems('小菜')"><div style="font-size:36px">🥬</div><h2>小菜</h2></div>
        <div class="category-card" onclick="showCategoryItems('飲料')"><div style="font-size:36px">🥤</div><h2>飲料</h2></div>
        <div class="category-card" onclick="showCategoryItems('甜點')"><div style="font-size:36px">🍮</div><h2>甜點</h2></div>
    </div>

    <div id="itemsContainer" aria-live="polite"></div>

    <div id="orderControls" style="margin-top:24px; display:flex; gap:12px; align-items:center; background:white; padding:16px; border-radius:12px; box-shadow: 0 2px 12px rgba(255,87,34,0.1);">
        <label for="customerName" style="font-weight:500; color:#e65100;">訂購人姓名：</label>
        <input id="customerName" type="text" placeholder="請輸入姓名" style="padding:8px 12px; border-radius:8px; border:1px solid #e0e0e0; background:#f8f9ff; font-size:15px;">
        <button id="submitOrderBtn" onclick="submitOrder()" style="background:linear-gradient(45deg, #ff5722, #ff7043); color:white; border:none; padding:8px 16px; border-radius:8px; cursor:pointer; font-weight:500; transition:all 0.2s">送出訂單</button>
    </div>

    <div id="orderHistory" style="margin-top:16px"></div> 

    <div id="cartModal" class="modal" role="dialog" aria-modal="true">
        <div class="modal-content">
            <span class="close" onclick="closeCart()">&times;</span>
            <h2>購物車</h2>
            <div id="cartItems"></div>
            <div id="cartTotal" class="cart-total"></div>
        </div>
    </div>
    
    <div class="contact-info-icon">
        <p>有問題請聯繫我們：</p>
        <a href="https://www.instagram.com/kshs_115/" target="_blank" class="ig-icon-link">
            <i class="fab fa-instagram"></i>
        </a>
    </div>
    <script>
        // *** Google Apps Script URL 已整合於此 ***
        const GOOGLE_SHEETS_URL = 'https://script.google.com/macros/s/AKfycbxEE9Nu-_
